#include <iostream>

using namespace std;

// Функція для виведення масиву
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//функція Coctail Sort
void cocktailSort(int arr[], int size) {
    bool swapped = true;
    int start = 0;
    int end = size - 1;

    while (swapped) {
        swapped = false;

// прохід зліва - направо
for (int i = start; i < end; ++i) {
    if (arr[i] > arr[i + 1]) {
        swap(arr[i], arr[i + 1]);
        swapped = true;
    }
}
    if (!swapped) break; 

        swapped = false; 
        end--; // останнє число не чіпаємо

// прохід справа наліво 
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i]; //метод 3 склянок 
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
        start++; 
    }
}

int main() {
    int numbers[] = {5, 25, 7, 2, 10};
    int size = 5;

    cout << "Starting sort: ";
    printArray(numbers, size);
    
    cocktailSort(numbers, size);
    
    cout << "Sorted with Cocktail Sort: ";
    printArray(numbers, size);

}