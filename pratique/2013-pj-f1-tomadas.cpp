#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int T1, T2, T3, T4;
    std::cin >> T1 >> T2 >> T3 >> T4;
    int total = 1;
    total += T1 - 1;
    total += T2 - 1;
    total += T3 - 1;
    total += T4 - 1;
    std::cout << total << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}