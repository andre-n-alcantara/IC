
#include <iostream>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;
    if (A > B && A > C) {
        if (B > C) {
            std::cout << B << std::endl;
        } else {
            std::cout << C << std::endl;
        }
    } else if (B > A && B > C) {
        if (A > C) {
            std::cout << A << std::endl;
        } else {
            std::cout << C << std::endl;
        }
    } else {
        if (A > B) {
            std::cout << A << std::endl;
        } else {
            std::cout << B << std::endl;
        }
    }
    return 0;
}
