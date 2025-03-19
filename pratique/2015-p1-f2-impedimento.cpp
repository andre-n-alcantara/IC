#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int L, R, D;
    std::cin >> L >> R >> D;
    if (R > 50 && L < R && R > D) {
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