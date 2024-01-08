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
    // �������� �� �������� ����� �����, ���� ������� n/2
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // ����������� ������� ���������� � ������ gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            // ��������� ��������, ���������� �� ������ gap ���� �� ������
            // � ��������� ������� �� ������� ����
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

    std::cout << "����� ����� �����������:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << A[i] << " ";
    }

    // ������ ������� ���������� ������� ���������
    shellSort(A, size);

    std::cout << "\n����� ���� ����������� �� ����������:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << A[i] << " ";
    }

    return 0;
}

