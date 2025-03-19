#include <iostream>

int main() {
    int v = 0;
    for (int i = 0; i < 6; i++) {
        char result;
        std::cin >> result;
        if (result == 'V') {
            v++;
        }
    }
    if (v >= 5) {
        std::cout << 1 << std::endl;
    } else if (v >= 3) {
        std::cout << 2 << std::endl;
    } else if (v >= 1) {
        std::cout << 3 << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    return 0;
}