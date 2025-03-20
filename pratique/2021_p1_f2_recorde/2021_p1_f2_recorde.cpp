#include <iostream>

int main() {
    int R, M, L;
    std::cin >> R >> M >> L;

    if (R < M) {
        std::cout << "RM\n";
    } else {
        std::cout << "*\n";
    }

    if (R < L) {
        std::cout << "RO\n";
    } else {
        std::cout << "*\n";
    }

    return 0;
}