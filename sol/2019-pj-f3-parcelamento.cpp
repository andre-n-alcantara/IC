#include <iostream>

int main() {
    int V, P;
    std::cin >> V >> P;

    int base = V / P;
    int resto = V % P;

    for (int i = 1; i <= P; i++) {
        if (i <= resto) {
            std::cout << base + 1 << std::endl;
        } else {
            std::cout << base << std::endl;
        }
    }

    return 0;
}