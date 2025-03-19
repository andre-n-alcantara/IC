#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int K, L;
    std::cin >> K >> L;

    if ((K + L) % 2 == 1 && (K + L) % 4 != 1) {
        std::cout << "final" << std::endl;
    } else if ((K + L) % 4 == 1) {
        std::cout << "semifinal" << std::endl;
    } else if ((K + L) % 2 == 0) {
        std::cout << "quartas" << std::endl;
    } else {
        std::cout << "oitavas" << std::endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}