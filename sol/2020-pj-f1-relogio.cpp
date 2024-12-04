#include <iostream>

int main() {
    int R, F, C;
    std::cin >> R >> F >> C;

    if (F > 3 * R || C < 95) {
        std::cout << "diminuir" << std::endl;
    } else if (F < 2 * R && C > 97) {
        std::cout << "aumentar" << std::endl;
    } else {
        std::cout << "manter" << std::endl;
    }

    return 0;
}