#include <iostream>

int main() {
    int B, T;
    std::cin >> B >> T;

    if (B < T * 70 / 160) {
        std::cout << 1 << std::endl;
    } else if (B > T * 70 / 160) {
        std::cout << 2 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }

    return 0;
}