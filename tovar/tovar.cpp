#include <iostream>
#include <string>

using namespace std;

class Tovar {
private:    
    string name;
public:
// конструктор дефолтний
Tovar() {
    name = " "; //можна через :
}
//гетери та сетери
void setName (string tovarName) { 
    name = tovarName; //можна через this->name = name;
}
string getName() const { 
    return name; 
}
//оператори зсуву 
friend ostream& operator<<(ostream& os, const Tovar& t) {
        os << t.name;
        return os;
    }
friend istream& operator>>(istream& is, Tovar& t) {
        is >> t.name;
        return is;
    }
};

class Sklad {
private:
Tovar* tovary; // динамічний масив товарів
int count;
int number;
string address;
public:
    //дефолтний конструктор
    Sklad() {
        tovary = nullptr;
        count = 0;
        number = 0;
        address = " ";
    }
    //конструктор з параметрами
    Sklad(int num, string add, int cnt) {
        number = num;
        address = add;
        count = cnt;
        tovary = new Tovar[count];
    }
    //конструктор копіювання 
    Sklad(const Sklad& other) {
        number = other.number;
        address = other.address;
        count = other.count;
        
        if (other.tovary != nullptr) {
            tovary = new Tovar[count];
            for (int i = 0; i < count; i++) {
                tovary[i] = other.tovary[i];
            }
        } else {
            tovary = nullptr;
        }
    }
    //деструктор
    ~Sklad() {
        if (tovary != nullptr) {
            delete[] tovary;
        }
    }
    //оператор присвоєння
    Sklad& operator=(const Sklad& other) {
        if (this == &other) return *this; // перевірка на самоприсвоєння

        delete[] tovary; // видалення старої пам'яті

        number = other.number;
        address = other.address;
        count = other.count;

        if (other.tovary != nullptr) {
            tovary = new Tovar[count];
            for (int i = 0; i < count; i++) {
                tovary[i] = other.tovary[i];
            }
        } else {
            tovary = nullptr;
        }
        return *this;
    }

    //оператор індексування 
    Tovar& operator[](int index) {
        return tovary[index];
    }

    //оператори зсуву 
    friend ostream& operator<<(ostream& os, const Sklad& s) {
        os << "Склад #" << s.number << " (Адреса: " << s.address << ", Товарів: " << s.count << ")";
        return os;
    }

    friend istream& operator>>(istream& is, Sklad& s) {
        cout << "Номер складу: "; is >> s.number;
        cout << "Адреса: "; is >> s.address;
        cout << "Кількість товарів:/n "; is >> s.count;

        delete[] s.tovary; 
        s.tovary = new Tovar[s.count];
        for (int i = 0; i < s.count; i++) {
            cout << "  Введіть назву товару: " << i + 1 << ": ";
            is >> s.tovary[i];
        }
        return is;
    }
    //геттери
    string getAddress() const { return address; }
    int getNumber() const { return number; }
    int getCount() const { return count; }
    //cеттери
    void setAddress(string add) { address = add; }
    void setNumber(int num) { number = num; }
    void setCount(int cnt) { 
        count = cnt; 
        delete[] tovary;
        tovary = new Tovar[count];
    }
    //метод для показу товарів складу
    void showTovary() const {
        if (count == 0) cout << "Склад порожній\n";
        for (int i = 0; i < count; i++) {
            cout << " - " << tovary[i] << endl;
        }
    }
};

int main() {

    Sklad number1, number2;

    cout << "Введіть дані для першого складу:\n";
    cin >> number1;
    cout << "\nВведіть дані для другого складу:\n";
    cin >> number2;

    //сортування за адресою 
    cout << "\n--- Склади в алфавітному порядку адрес ---\n";
    if (number1.getAddress() <= number2.getAddress()) {
        cout << number1 << endl << number2 << endl;
    } else {
        cout << number2 << endl << number1 << endl;
    }

    // Список товарів складу з меншим номером
    cout << "\n--- Товари зі складу з меншим номером ---\n";
    if (number1.getNumber() < number2.getNumber()) {
        number1.showTovary();
    } else {
        number2.showTovary();
    }

    // Створення нового складу шляхом копіювання того, де менше товарів
    cout << "\n--- Копіювання складу з меншою кількістю товарів ---\n";
    Sklad s_copy;
    if (number1.getCount() < number2.getCount()) {
        s_copy = number1; // Тут спрацює наш operator=
    } else {
        s_copy = number2;
    }

    cout << "Новий склад створено! Дані:\n" << s_copy << endl;
    s_copy.showTovary();

    return 0;
}



   