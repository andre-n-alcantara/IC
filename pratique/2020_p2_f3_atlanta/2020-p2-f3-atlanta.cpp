#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;

    if (A % 2 == 0 || B < (A / 2) * 2 + 1) {
        std::cout << "-1 -1" << std::endl;
        return 0;
    }

    int L = (A / 2) + 1;
    int C = (B + A / 2) / L;

    if (L > C) std::swap(L, C);

    std::cout << L << " " << C << std::endl;

    return 0;
}