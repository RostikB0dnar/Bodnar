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

void shellSort(int arr[], int n) {
    // Починаємо із величини розмір кроку, який дорівнює n/2
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Застосовуємо вставне сортування з кроком gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            // Порівнюємо елементи, розташовані на відстані gap один від одного
            // і здійснюємо вставку на потрібне місце
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}


int main() {

    int size = 7;
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
    shellSort(A, size);

    std::cout << "\nМасив після сортуванням за зростанням:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << A[i] << " ";
    }

    return 0;
}

