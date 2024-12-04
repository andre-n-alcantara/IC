#include <iostream>

int main() {
    int wins = 0;
    for (int i = 0; i < 6; i++) {
        char result;
        std::cin >> result;
        if (result == 'V') {
            wins++;
        }
    }
    if (wins >= 5) {
        std::cout << 1 << std::endl;
    } else if (wins >= 3) {
        std::cout << 2 << std::endl;
    } else if (wins >= 1) {
        std::cout << 3 << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    return 0;
}