#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int L, C;
    std::cin >> L >> C;
    std::cout << ((L + C) % 2 ? 0 : 1) << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}