#include <iostream>
#include <vector>

// Function template for bubble sort
template <typename T>
void bubbleSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    try {
        // Example using integer values
        std::vector<int> intArray = {64, 34, 25, 12, 22, 11, 90};
        std::cout << "Original Integer Array: ";
        for (int num : intArray) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        bubbleSort(intArray);

        std::cout << "Sorted Integer Array: ";
        for (int num : intArray) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        // Example using double values
        std::vector<double> doubleArray = {3.14, 1.1, 2.2, 0.5, 9.8};
        std::cout << "\nOriginal Double Array: ";
        for (double num : doubleArray) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        bubbleSort(doubleArray);

        std::cout << "Sorted Double Array: ";
        for (double num : doubleArray) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        //
