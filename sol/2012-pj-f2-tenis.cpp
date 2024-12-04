
#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;
    if (x >= 0 && x <= 432 && y >= 0 && y <= 468) {
        std::cout << "dentro" << std::endl;
    } else {
        std::cout << "fora" << std::endl;
    }
    return 0;
}
