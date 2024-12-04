#include <iostream>

int main() {
    long long int N;
    std::cin >> N;

    for (long long int i = 2; i * i <= N; ++i) {
        if (N % i == 0) {
            std::cout << "S" << std::endl;
            return 0;
        }
    }

    std::cout << "N" << std::endl;
    return 0;
}