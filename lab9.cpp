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
                // ���� ��������, ���� ���� ����������� � ������������� �������
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ������� ��� ��������� ��������� ������
int binarySearch(int* arr, int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // �������� �������, ��������� ���� ������
        }
        else if (arr[mid] < target) {
            left = mid + 1; // ������ � ����� �������
        }
        else {
            right = mid - 1; // ������ � ��� �������
        }
    }

    return -1; // ������� �� ��������
}

int main() {
    // �������� �������� ����� ��� ���������� ������
    int k = 2;
    int size = 20 + 0.6 * k; // ����� ������ �����
    // ��������� ��������� ����� �� ���������� ���� ����������� �������
    int* N = new int[size];
    for (int i = 0; i < size; i++) {
        N[i] = getRandomNumber(10, 100); // ������ ��������� ����� �� ������
    }

    bubbleSort(N, size);

    cout << "³����������� �����" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << N[i] << " ";
    }
    cout << endl;

    // ������� ����� ��� ������������ ��������� ������
    std::sort(N, N + size);

    // ������ ������� �������� �������� �����
    int target = getRandomNumber(10, 100); // �������� ��������� �����, ��� ����������
    int index = binarySearch(N, size, target);

    // �������� ���������
    if (index != -1) {
        std::cout << "������� " << target << " �������� �� ������� " << index << std::endl;
    }
    else {
        std::cout << "������� " << target << " �� ��������" << std::endl;
    }

    // ��������� ���'���, �� ���� ������� �� ��������� �����
    delete[] N;

    return 0;
}
