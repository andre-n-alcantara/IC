
#include <iostream>

int main() {
    int L, R, D;
    std::cin >> L >> R >> D;
    if (R > 50 && L < R && R > D) {
        std::cout << "S" << std::endl;
    } else {
        std::cout << "N" << std::endl;
    }
    return 0;
}
