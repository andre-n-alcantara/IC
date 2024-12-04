#include <iostream>

int main() {
    int P, R;
    std::cin >> P >> R;

    if (P == 1 && R == 0) {
        std::cout << "B" << std::endl;
    } else if (P == 0 && R == 0) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "A" << std::endl;
    }

    return 0;
}