#include <iostream>
#include <cstring>

void computeLPS(const char* P, int m, int* lps) {
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < m) {
        if (P[i] == P[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int findFirstOccurrence(const char* S, int n, const char* P, int m) {
    int lps[m];
    computeLPS(P, m, lps);

    int i = 0;
    int j = 0;

    while (i < n) {
        if (P[j] == S[i]) {
            j++;
            i++;
        }

        if (j == m) {
            return i - j; // Знайдено входження Р в S, повертаємо індекс першого елемента входження
            j = lps[j - 1];
        }
        else if (i < n && P[j] != S[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return -1; // Якщо не знайдено входження Р в S
}

int main() {
    const char* S = "This is a sample text for string searching.";
    const char* P = "sample";

    int n = strlen(S);
    int m = strlen(P);

    int index = findFirstOccurrence(S, n, P, m);

    if (index != -1)
        std::cout << "Перше входження Р у S знаходиться по індексу: " << index << std::endl;
    else
        std::cout << "Р не знайдено в S" << std::endl;

    return 0;
}
