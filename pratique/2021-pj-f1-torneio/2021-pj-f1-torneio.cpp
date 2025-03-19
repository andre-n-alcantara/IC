#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int wins = 0;
    for (int i = 0; i < 6; i++) {
        char result;
        std::cin >> result;
        if (result == 'V') {
            wins++;
        }
    }
    if (wins >= 5) {
        std::cout << 1 << std::endl;
    } else if (wins >= 3) {
        std::cout << 2 << std::endl;
    } else if (wins >= 1) {
        std::cout << 3 << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}