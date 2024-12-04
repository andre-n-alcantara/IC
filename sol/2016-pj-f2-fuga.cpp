#include <iostream>

int main() {
    int H, P, F, D;
    std::cin >> H >> P >> F >> D;

    int distance = (H - F + 16) % 16;
    if (D == -1) {
        distance = 16 - distance;
    }

    if (distance <= (P - F + 16) % 16) {
        std::cout << "S" << std::endl;
    } else {
        std::cout << "N" << std::endl;
    }

    return 0;
}