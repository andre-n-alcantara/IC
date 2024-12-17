#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int L, C;
    std::cin >> L >> C;

    int tipo1 = (L * C) - 4;
    int tipo2 = (L + C - 2) * 2 - 4;

    std::cout << tipo1 << std::endl;
    std::cout << tipo2 << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}