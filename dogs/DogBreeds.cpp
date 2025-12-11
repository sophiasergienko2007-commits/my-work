#include <iostream>
#include <string>

using namespace std;

// Перелічення для порід собак
//еnum - тип даних, який дозволяє створювати набір іменованих констант.
enum DogBreeds { LABRADOR, BEAGLE, BULLDOG, HUSKY, POODLE, BREEDS_COUNT }; // BREEDS_COUNT використовується для визначення кількості порід (5)

// Функція для випадкової генерації порід собак в масив
void generateDogs(DogBreeds arr[], int n)
 {
    for (int i = 0; i < n; i++) 
    {
        arr[i] = static_cast<DogBreeds>(rand() % BREEDS_COUNT); //static_cast — перетворення типу
    }
}

// Функція для перетворення породи на текст
string breedToString(DogBreeds breed) 
{
    switch (breed) 
    {
        case LABRADOR: return "Labrador";
        case BEAGLE: return "Beagle";
        case BULLDOG: return "Bulldog";
        case HUSKY: return "Husky";
        case POODLE: return "Poodle";
        default: return "Unknown";
    }
}

// Функція перевірки чи є порода в масиві
bool isBreedInArray(DogBreeds arr[], int n, string input)
 {
    for (int i = 0; i < n; i++) 
    {
        if (breedToString(arr[i]) == input) 
        {
            return true;
        }
    }
    return false;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // ініціалізація генератора випадкових чисел

    const int n = 10;
    DogBreeds dogs[n];

    generateDogs(dogs, n);

    // Виведення масиву для перевірки (можна потім прибрати)
    cout << "Список порід в масиві: ";
    for (int i = 0; i < n; i++) {
        cout << breedToString(dogs[i]) << " ";
    }
    cout << endl;

    string input;

    while (true) 
    {
        cout << "Введіть породу собаки: ";
        cin >> input;

        if (isBreedInArray(dogs, n, input)) 
        {
            cout << "Порода знайдена!";
            break;
        } 
        else 
        {
            cout << "Такої породи в масиві немає. Спробуйте ще раз.\n";
        }
    }

    return 0;
}
