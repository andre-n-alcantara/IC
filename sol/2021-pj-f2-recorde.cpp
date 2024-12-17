#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int R, M, L;
    std::cin >> R >> M >> L;

    if (R < M)
        std::cout << "RM" << std::endl;
    else
        std::cout << "*" << std::endl;

    if (R < L)
        std::cout << "RO" << std::endl;
    else
        std::cout << "*" << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}