#pragma once

//бісектриса
double bisector(double a, double b, double c);

//рекурсивна і нерекурсивна функції
double poly_recursive(double a[], int n, double x); 
double poly_iterative(double a[], int n, double x);

// функція вводу масиву
void inputArray(double arr[], int n, const char* name);

//функція вищого порядку 
double product(double arr[], int n, double (*f)(double));

// функції для передачі у функцію вищого порядку
double f_x(double x);
double f_xi(double x);
