
#include <iostream>
#include <cmath>

int main() {
    int L, A, P, R;
    while (std::cin >> L >> A >> P >> R) {
        double radius = std::sqrt(std::pow(L, 2) + std::pow(A, 2) + std::pow(P, 2));
        if (radius <= R) {
            std::cout << "S" << std::endl;
        } else {
            std::cout << "N" << std::endl;
        }
    }
    return 0;
}
