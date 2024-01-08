#include <iostream>

using namespace std;

int sumOfSquares(int n) {
    
    if (n == 1) {
        return 1;
    }
    else {
        return n * n + sumOfSquares(n - 1);
    }
}

int main() {
    int n;
    std::cout << "������ n: ";
    std::cin >> n;

    int result = sumOfSquares(n);
    std::cout << "���� �������� ����� �� 1 �� " << n << " = " << result << std::endl;

    return 0;
}