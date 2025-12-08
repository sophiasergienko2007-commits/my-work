#include <iostream>
#include <cmath>
#include "functions.h"
using namespace std;

//бісектриси трикутника
double bisector(double a, double b, double c) 
{
    return sqrt(a * b * ((a + b) * (a + b) - c * c)) / (a + b);
}

//рекурсивна функція для обчислення виразу 
double poly_recursive(double a[], int n, double x) 
{
    if (n == 0) return 0;
    return a[20 - n] * pow(x, n - 1) + poly_recursive(a, n - 1, x);
}

//нерекурсивна функція для обчислення виразу
double poly_iterative(double a[], int n, double x)
 {
    double sum = 0;
    int power = n - 1;
    for (int i = 0; i < n; i++) 
    {
        sum = sum + a[i] * pow(x, power);
        power = power - 1;
    }
    return sum;
}

//ввід масиву 
void inputArray(double arr[], int n, const char* name) 
{
    cout << "Введіть масив " << name << " (" << n << " елементів):\n";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
}

//функція вищого порядку 
double product(double arr[], int n, double (*f)(double)) 
{
    double result = 1.0;
    for (int i = 0; i < n; i++) 
    {
        result = result * f(arr[i]);
    }
    return result;
}

// f(x) = 1/(|x| + 0.1)
double f_x(double x)
{
    return 1.0 / (fabs(x) + 0.1)+0.1; //fabs - повертає модуль числа з плаваючою комою
}

// f(x) = (1 - x²)
double f_xi(double x) 
{
    return (1 - x * x);
}
