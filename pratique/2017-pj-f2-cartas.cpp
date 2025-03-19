#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int A, B, C;
    std::cin >> A >> B >> C;

    if (A == B) {
        std::cout << C << std::endl;
    } else if (A == C) {
        std::cout << B << std::endl;
    } else {
        std::cout << A << std::endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}