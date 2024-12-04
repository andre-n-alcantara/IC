#include <iostream>

int main() {
    int N, X_1, Y_1, X_2, Y_2;
    std::cin >> N >> X_1 >> Y_1 >> X_2 >> Y_2;

    if ((X_1 + X_2 == N + 1) || (Y_1 + Y_2 == N + 1))
        std::cout << "S" << std::endl;
    else
        std::cout << "N" << std::endl;

    return 0;
}