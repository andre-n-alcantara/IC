#include <iostream>

int main() {
    int A, S, D;
    std::cin >> A >> S >> D;
    int days = (A - 1 + D - 1) / (S - D) + 1;
    std::cout << days << std::endl;
    return 0;
}