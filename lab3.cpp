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
    std::cout << "¬вед≥ть n: ";
    std::cin >> n;

    int result = sumOfSquares(n);
    std::cout << "—ума квадрат≥в чисел в≥д 1 до " << n << " = " << result << std::endl;

    return 0;
}