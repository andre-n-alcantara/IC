#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    double result = 1.0;
    for (int i = 0; i < n; i++) {
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