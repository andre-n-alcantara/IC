#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int xm, ym, xr, yr;
    std::cin >> xm >> ym >> xr >> yr;
    std::cout << std::abs(xm - xr) + std::abs(ym - yr) << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}