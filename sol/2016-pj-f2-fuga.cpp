#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int H, P, F, D;
    std::cin >> H >> P >> F >> D;

    int distance = (H - F + 16) % 16;
    if (D == -1) {
        distance = 16 - distance;
    }

    if (distance <= (P - F + 16) % 16) {
        std::cout << "S" << std::endl;
    } else {
        std::cout << "N" << std::endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}