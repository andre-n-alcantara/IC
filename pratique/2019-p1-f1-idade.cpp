#include <iostream>

int main() {
    int M, A, B;
    std::cin >> M >> A >> B;
    int sum = M - A - B;
    if (sum > A && sum > B) {
        std::cout << sum << std::endl;
    } else if (A > sum && A > B) {
        std::cout << A << std::endl;
    } else {
        std::cout << B << std::endl;
    }
    return 0;
}