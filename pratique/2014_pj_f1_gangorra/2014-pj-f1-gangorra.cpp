#include <ctime>
#include <iostream>

int main() {
    int P1, C1, P2, C2;
    std::cin >> P1 >> C1 >> P2 >> C2;

    if (P1 * C1 == P2 * C2) {
        std::cout << "0" << std::endl;
    } else if (P1 * C1 > P2 * C2) {
        std::cout << "-1" << std::endl;
    } else {
        std::cout << "1" << std::endl;
    }

    
return 0;
}