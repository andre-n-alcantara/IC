#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int A, B, C;
    std::cin >> A >> B >> C;

    if (A >= B || B >= C) {
        std::cout << 3 << std::endl;
    } else if (A + B < C) {
        std::cout << 1 << std::endl;
    } else if (A < B && B < C) {
        std::cout << 2 << std::endl;
    } else {
        std::cout << 2 << std::endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}