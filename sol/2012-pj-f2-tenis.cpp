#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int x, y;
    std::cin >> x >> y;
    if (x >= 0 && x <= 432 && y >= 0 && y <= 468) {
        std::cout << "dentro" << std::endl;
    } else {
        std::cout << "fora" << std::endl;
    }
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}