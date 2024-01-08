#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

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

// Функція для виконання двійкового пошуку
int binarySearch(int* arr, int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Знайдено елемент, повертаємо його індекс
        }
        else if (arr[mid] < target) {
            left = mid + 1; // Шукаємо у правій половині
        }
        else {
            right = mid - 1; // Шукаємо у лівій половині
        }
    }

    return -1; // Елемент не знайдено
}

int main() {
    // Генеруємо випадкові числа для заповнення масиву
    int k = 2;
    int size = 20 + 0.6 * k; // Розмір масиву чисел
    // Створюємо динамічний масив та заповнюємо його випадковими числами
    int* N = new int[size];
    for (int i = 0; i < size; i++) {
        N[i] = getRandomNumber(10, 100); // Додаємо випадкове число до масиву
    }

    bubbleSort(N, size);

    cout << "Відсортований масив" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << N[i] << " ";
    }
    cout << endl;

    // Сортуємо масив для використання двійкового пошуку
    std::sort(N, N + size);

    // Шукаємо елемент ґратуючи двійковий пошук
    int target = getRandomNumber(10, 100); // Генеруємо випадкове число, яке шукатимемо
    int index = binarySearch(N, size, target);

    // Виводимо результат
    if (index != -1) {
        std::cout << "Елемент " << target << " знайдено на позиції " << index << std::endl;
    }
    else {
        std::cout << "Елемент " << target << " не знайдено" << std::endl;
    }

    // Звільняємо пам'ять, що була виділена під динамічний масив
    delete[] N;

    return 0;
}
