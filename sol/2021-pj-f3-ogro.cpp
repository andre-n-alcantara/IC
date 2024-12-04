
#include <iostream>

int main() {
    int N;
    std::cin >> N;

    if (N <= 5) {
        for (int i = 0; i < N; i++) {
            std::cout << "I";
        }
        std::cout << std::endl;
        std::cout << "*" << std::endl;
    } else {
        for (int i = 0; i < 5; i++) {
            std::cout << "I";
        }
        std::cout << std::endl;
        for (int i = 0; i < N - 5; i++) {
            std::cout << "I";
        }
        std::cout << std::endl;
    }

    return 0;
}
