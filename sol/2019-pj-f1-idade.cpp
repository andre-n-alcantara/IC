#include <iostream>

int main() {
    int M, A, B;
    std::cin >> M >> A >> B;
    int C = M - A - B;
    if (A > B && A > C) {
        std::cout << A << std::endl;
    } else if (B > A && B > C) {
        std::cout << B << std::endl;
    } else {
        std::cout << C << std::endl;
    }
    return 0;
}