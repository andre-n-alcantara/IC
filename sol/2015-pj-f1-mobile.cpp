
#include <iostream>

int main() {
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    if (A == B + C + D && B + C == D && B == C) {
        std::cout << "S" << std::endl;
    } else {
        std::cout << "N" << std::endl;
    }

    return 0;
}
