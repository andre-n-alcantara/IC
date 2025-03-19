#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int P1, C1, P2, C2;
    std::cin >> P1 >> C1 >> P2 >> C2;

    if (P1 * C1 == P2 * C2) {
        std::cout << "0" << std::endl;
    } else if (P1 * C1 > P2 * C2) {
        std::cout << "-1" << std::endl;
    } else {
        std::cout << "1" << std::endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}