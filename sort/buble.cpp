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
//функція порівняння
void bitonicCompare(int arr[], int i, int j, int direction) {
    if (direction == (arr[i] > arr[j])) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
/*оце ще не розібрала 
// функція злиття
void bitonicMerge(int arr[], int low, int cnt, int dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        for (int i = low; i < low + k; i++) {
            bitonicCompare(arr, i, i + k, dir);
        }
        bitonicMerge(arr, low, k, dir);
        bitonicMerge(arr, low + k, k, dir);
    }
}

// основна функція 
void bitonicSort(int arr[], int low, int cnt, int dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        bitonicSort(arr, low, k, 1);  
        bitonicSort(arr, low + k, k, 0); 
        bitonicMerge(arr, low, cnt, dir);
    }
}
*/
int main() {
    int numbers[] = {5, 25, 7, 2, 10};
    int size = 5;

    cout << "Starting sort for Coctail: ";
    printArray(numbers, size);
    
    cocktailSort(numbers, size);
    
    cout << "Sorted with Cocktail Sort: ";
    printArray(numbers, size);

    int bitonicNumbers[] = {10, 30, 20, 40, 5, 15, 25, 35};
    int bSize = 8;

    cout << "\nStarting sort for Bitonic: ";
    printArray(bitonicNumbers, bSize);

    //bitonicSort(bitonicNumbers, 0, bSize, 1);
    
    cout << "Sorted with Bitonic Sort: ";
    printArray(bitonicNumbers, bSize);

    return 0;

}