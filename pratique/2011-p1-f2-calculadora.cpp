#include <iostream>

int main() {
    int N;
    std::cin >> N;
    double result = 1.0;
    for (int i = 0; i < N; i++) {
        int digit;
        char op;
        std::cin >> digit >> op;
        if (op == '*') {
            result *= digit;
        } else {
            result /= digit;
        }
    }
    std::cout << (int)result << std::endl;
    return 0;
}