
#include <iostream>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    if (A >= B || B >= C) {
        std::cout << 3 << std::endl;
    } else if (A + B < C) {
        std::cout << 1 << std::endl;
    } else if (A < B && B < C) {
        std::cout << 2 << std::endl;
    } else {
        std::cout << 2 << std::endl;
    }

    return 0;
}
