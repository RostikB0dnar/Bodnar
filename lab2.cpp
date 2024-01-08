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

void findMinMax(int arr[], int n, int& minVal, int& maxVal) {
    minVal = arr[0];
    maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
}

void partOne()
{
    int r;
    cout << "Введіть розмірність масиву: ";
    cin >> r;
    int arr[r];

    for (int i = 0; i < r; i++)
    {
        arr[i] = getRandomNumber(-50, 50);
        cout << arr[i] << " ";
    }
    cout << endl;
    int n = r;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Масив після сортування:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int minVal, maxVal;
    findMinMax(arr, n, minVal, maxVal);
    cout << "Мінімальний елемент: " << minVal << endl;
    cout << "Максимальний елемент: " << maxVal << endl;

    int minIndex = -1;
    int maxIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == minVal) {
            minIndex = i;
        }
        if (arr[i] == maxVal) {
            maxIndex = i;
        }
    }

    if (minIndex != -1 && maxIndex != -1) {
        int newSize = minIndex - maxIndex + 1;
        if (newSize > 0) {
            int* newArray = new int[newSize];
            for (int i = maxIndex; i <= minIndex; i++) {
                newArray[i - maxIndex] = arr[i];
            }

            cout << "Відсортовані елементи:" << endl;
            for (int i = 0; i < newSize; i++) {
                cout << newArray[i] << " ";
            }
            cout << endl;
            cout << "Розмір динамічного масиву: " << newSize;

            delete[] newArray;
        }
    }
}

void partTwo()
{
    int r;
    cout << "Введіть кількість рядків матриці: ";
    cin >> r;
    int s;
    cout << "Введіть кількість стовпців матриці: ";
    cin >> s;
    int arr[r][s];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < s; j++)
        {
            arr[i][j] = getRandomNumber(-50, 50);
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    int* newArray[25];
    int sizeNewArray = 0;
    cout << "Елементи над головною діагоналлю: " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (i < j)
            {
                newArray[sizeNewArray] = &arr[i][j];
                sizeNewArray++;
                cout << *newArray[sizeNewArray - 1] << " "; // Виведення кожного елементу
            }
        }
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "Part one:" << endl;
    partOne();
    cout << endl;
    cout << endl;
    cout << "Part two: " << endl;
    partTwo();

    return 0;
}