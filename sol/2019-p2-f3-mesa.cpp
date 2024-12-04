
#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;
    A %= 3;
    B %= 3;
    if (B == A) B = (B + 1) % 3;
    std::cout << (3 - A - B) % 3 + 1 << std::endl;
    return 0;
}
