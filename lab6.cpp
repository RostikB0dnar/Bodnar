#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Обмін елементів, якщо вони знаходяться в неправильному порядку
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Переміщуємо елементи, які більше за key, на одну позицію вперед
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}




int main() {

    int size = 6;
    int A[size];
    for (int i = 0; i < size; i++)
        {
        A[i] = getRandomNumber(10, 100);
        }

    std::cout << "Масив перед сортуванням:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << A[i] << " ";
    }

    // Виклик функції сортування методом бульбашки
    bubbleSort(A, size);

    std::cout << "\nМасив після сортуванням за зростанням:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << A[i] << " ";
    }

    return 0;
}

