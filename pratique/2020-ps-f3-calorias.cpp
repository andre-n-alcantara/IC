#include <iostream>

int main() {
    int E1, E2, E3, X;
    std::cin >> E1 >> E2 >> E3 >> X;
    if (E2 - E1 <= X) {
        std::cout << E2 << std::endl;
    } else {
        std::cout << E3 << std::endl;
    }
    return 0;
}