#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int L, D, K, P;
    std::cin >> L >> D >> K >> P;
    int pedagios = (L + D - 1) / D;
    int custo_total = L * K + pedagios * P;
    std::cout << custo_total << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}