#include <iostream>
using namespace std;

// Структура комплексного числа
struct Complex
{
    double re; // дійсна частина
    double im; // уявна частина
};

// Функції для арифметичних операцій

Complex add(Complex a, Complex b)
{
    Complex c;
    c.re = a.re + b.re;
    c.im = a.im + b.im;
    return c;
}

Complex sub(Complex a, Complex b)
{
    Complex c;
    c.re = a.re - b.re;
    c.im = a.im - b.im;
    return c;
}

Complex mul(Complex a, Complex b)
{
    Complex c;
    c.re = a.re * b.re - a.im * b.im;
    c.im = a.re * b.im + a.im * b.re;
    return c;
}

Complex divide(Complex a, Complex b)
{
    Complex c;
    double d = b.re * b.re + b.im * b.im;
    c.re = (a.re * b.re + a.im * b.im) / d;
    c.im = (a.im * b.re - a.re * b.im) / d;
    return c;
}

// Функція для виводу комплексного числа
void printComplex(Complex c)
{
    cout << c.re << " + " << c.im << "i";
}

int main()
{
    int n;
    cout << "Введіть кількість комплексних чисел: ";
    cin >> n;

    Complex arr[n]; 

    cout << "Введіть числа у форматі: Re Im\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Число " << i + 1 << ": ";
        cin >> arr[i].re >> arr[i].im;
    }

    // 1) Сума всіх елементів
    Complex sum = {0, 0};
    for (int i = 0; i < n; i++)
    {
        sum = add(sum, arr[i]);
    }

    // 2) Середнє арифметичне
    Complex average;
    average.re = sum.re / n;
    average.im = sum.im / n;

    // 3) Добуток елементів, дійсна частина яких > за дійсну частину останнього елемента
    Complex product = {1, 1};
    Complex last = arr[n - 1];

    for (int i = 0; i < n; i++)
    {
        if (arr[i].re > last.re)
        {
            product = mul(product, arr[i]);
        }
    }

    // Вивід результатів
    cout << "\nСума: ";
    printComplex(sum);

    cout << "\nСереднє арифметичне: ";
    printComplex(average);

    cout << "\nДобуток елементів з більшою дійсною частиною: ";
    printComplex(product);

    cout << endl;

    return 0;
}
