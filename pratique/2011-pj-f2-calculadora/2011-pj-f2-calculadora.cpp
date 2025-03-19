#include <ctime>
#include <iostream>
#include <string>

int main() {
    std::clock_t startTime = std::clock();
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
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}