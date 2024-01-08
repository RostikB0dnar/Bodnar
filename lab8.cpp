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

// ������� ��� ����� �������
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// �������� ������� ��� ������ �����
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // ������� ������ ������� �� �������
    int left = low - 1;
    int right = high + 1;

    while (true) {
        do {
            left++;
        } while (arr[left] < pivot);

        do {
            right--;
        } while (arr[right] > pivot);

        if (left >= right)
            return right;

        swap(arr[left], arr[right]);
    }
}

// ������� ������� �������� ����������
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int partitionIndex = partition(arr, low, high);

        // ���������� ������� �� ������� ������
        quickSort(arr, low, partitionIndex);
        quickSort(arr, partitionIndex + 1, high);
    }
}

// ������ ���� �������� arr[l..m] � arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // ��������� ���������� ������
    int L[n1], R[n2];

    // ��������� ����� � �������� ������ L[] �� R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // ������ ���������� ������ ����� � arr[l..r]
    int i = 0; // ���������� ������ ������� ��������
    int j = 0; // ���������� ������ ������� ��������
    int k = l; // ���������� ������ ������� ������

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // ��������� ������� L[], ���� ��� �
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // ��������� ������� R[], ���� ��� �
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// ������� ��� ���������� ������ ������� ������
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // ��������� �������� ������
        int m = l + (r - l) / 2;

        // ���������� ������� ����� �������� �� ����� ��������
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // ������ ���� ������������ ��������
        merge(arr, l, m, r);
    }
}

int main() {

    int size = 6;
    int A[size];
    for (int i = 0; i < size; i++)
    {
        A[i] = getRandomNumber(10, 100);
    }

    std::cout << "����� ����� �����������:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << A[i] << " ";
    }

    // ������ ������� ���������� ������� ���������
    quickSort(A, 0, size - 1);

    std::cout << "\n����� ���� ����������� �� ����������:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << A[i] << " ";
    }
    cout << endl;
    cout << endl;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = getRandomNumber(10, 100);
        cout << arr[i] << " ";
    }
    mergeSort(arr, 0, size - 1);
    cout << endl;

    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}