#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int D;
    std::cin >> D;

    if (D <= 800)
        std::cout << 1 << std::endl;
    else if (D <= 1400)
        std::cout << 2 << std::endl;
    else
        std::cout << 3 << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}