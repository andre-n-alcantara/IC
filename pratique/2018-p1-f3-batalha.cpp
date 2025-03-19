#include <iostream>

int main() {
    int A1, D1, A2, D2;
    std::cin >> A1 >> D1 >> A2 >> D2;

    if (D1 == A2 && D2 != A1) {
        std::cout << 2 << std::endl;
    } else if (D2 == A1 && D1 != A2) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}