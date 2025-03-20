#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;

    int C = (A + B) / 2 - (A < B ? A : B);

    std::cout << C << std::endl;

    return 0;
}