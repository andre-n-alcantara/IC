#include <iostream>

int main() {
    int D;
    std::cin >> D;
    D -= 3; // subtrair a distância do emissor até o acelerador
    if (D % 8 == 0) {
        std::cout << "1" << std::endl;
    } else if (D % 8 <= 4) {
        std::cout << "2" << std::endl;
    } else {
        std::cout << "3" << std::endl;
    }
    return 0;
}