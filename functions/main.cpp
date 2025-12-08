#include <iostream>
#include <cmath>
#include "functions.h"
using namespace std;

int main() {

   
    //бісектриси трикутника
    double a, b, c;
    cout << "Введіть сторони трикутника a b c: ";
    cin >> a >> b >> c;

    // перевірка на існування трикутника
    if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a)) {
        cout << "Помилка: сторони не утворюють трикутник!\n\n";
    } else {
        cout << "\nБісектриса проти a: " << bisector(b, c, a);
        cout << "\nБісектриса проти b: " << bisector(a, c, b);
        cout << "\nБісектриса проти c: " << bisector(a, b, c) << "\n\n";
    }
 


    // ======================================
    // 2. Поліном
    // ======================================
    double x;
    double coef[20];

    cout << "\nВведіть число x: ";
    cin >> x;

    cout << "Введіть 20 коефіцієнтів a1 ... a20:\n";
    for (int i = 0; i < 20; i++) cin >> coef[i];

    double r1 = poly_recursive(coef, 20, x);
    double r2 = poly_iterative(coef, 20, x);

    cout << "\nРекурсивний результат = " << r1;
    cout << "\nНерекурсивний результат = " << r2 << "\n\n";


    // ======================================
    // 3. Масиви X, Y, Z
    // ======================================
    double X[20], Y[20], Z[20];

    inputArray(X, 20, "X");
    inputArray(Y, 20, "Y");
    inputArray(Z, 20, "Z");

    double prodX = product(X, 20, f_x);
    double prodY = product(Y, 20, f_xi);

    double u;

    if (prodX + 0.1 > 1 && prodY > 1)
        u = prodX;
    else
        u = product(Z, 20, f_x);

    cout << "\nЗначення u = " << u << "\n";

    return 0;
}

