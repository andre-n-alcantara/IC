#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int A, S, D;
    std::cin >> A >> S >> D;
    int days = (A + D - 1) / (S - D);
    std::cout << days << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}