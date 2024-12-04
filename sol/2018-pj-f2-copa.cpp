
#include <iostream>

int main() {
    int K, L;
    std::cin >> K >> L;

    if ((K + L) % 2 == 1 && (K + L) % 4 != 1) {
        std::cout << "final" << std::endl;
    } else if ((K + L) % 4 == 1) {
        std::cout << "semifinal" << std::endl;
    } else if ((K + L) % 2 == 0) {
        std::cout << "quartas" << std::endl;
    } else {
        std::cout << "oitavas" << std::endl;
    }

    return 0;
}
