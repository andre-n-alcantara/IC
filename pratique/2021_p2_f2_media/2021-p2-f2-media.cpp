#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;

    if (A == B) {
        std::cout << A - 1 << std::endl;
    } else if (A + 1 == B) {
        std::cout << A << std::endl;
    } else {
        int C = (A + B) / 2;
        if ((A + B + C) % 3 == 0 && (A <= C && C <= B)) {
            std::cout << C << std::endl;
        } else {
            std::cout << B - 1 << std::endl;
        }
    }

    return 0;
}