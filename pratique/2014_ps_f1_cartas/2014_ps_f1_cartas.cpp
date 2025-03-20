#include <iostream>

int main() {
    int cards[5];
    for (int i = 0; i < 5; i++) {
        std::cin >> cards[i];
    }

    bool crescente = true;
    bool decrescente = true;

    for (int i = 0; i < 4; i++) {
        if (cards[i] > cards[i + 1]) {
            crescente = false;
        }
        if (cards[i] < cards[i + 1]) {
            decrescente = false;
        }
    }

    if (crescente) {
        std::cout << "C" << std::endl;
    } else if (decrescente) {
        std::cout << "D" << std::endl;
    } else {
        std::cout << "N" << std::endl;
    }

    return 0;
}