#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    if (a <= b && b <= c) {
        std::cout << b << std::endl;
    } else if (a <= c && c <= b) {
        std::cout << c << std::endl;
    } else {
        std::cout << a << std::endl;
    }

    return 0;
}