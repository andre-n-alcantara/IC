
#include <iostream>

int main() {
    int D;
    std::cin >> D;

    if (D <= 800)
        std::cout << 1 << std::endl;
    else if (D <= 1400)
        std::cout << 2 << std::endl;
    else
        std::cout << 3 << std::endl;

    return 0;
}
