#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    if (A == B + C + D && B + C == D && B == C) {
        std::cout << "S" << std::endl;
    } else {
        std::cout << "N" << std::endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}