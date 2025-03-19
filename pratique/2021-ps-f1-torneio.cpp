#include <iostream>

int main() {
    int vitorias = 0;
    char resultado;
    for (int i = 0; i < 6; i++) {
        std::cin >> resultado;
        if (resultado == 'V') {
            vitorias++;
        }
    }
    if (vitorias >= 5) {
        std::cout << 1 << std::endl;
    } else if (vitorias >= 3) {
        std::cout << 2 << std::endl;
    } else if (vitorias >= 1) {
        std::cout << 3 << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    return 0;
}