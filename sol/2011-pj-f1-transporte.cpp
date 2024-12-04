
#include <iostream>

int main() {
    int A, B, C, X, Y, Z;
    std::cin >> A >> B >> C;
    std::cin >> X >> Y >> Z;

    if (C > Z) {
        std::cout << 0 << std::endl;
    } else {
        int width = X / A;
        int length = Y / B;
        std::cout << width * length << std::endl;
    }

    return 0;
}
