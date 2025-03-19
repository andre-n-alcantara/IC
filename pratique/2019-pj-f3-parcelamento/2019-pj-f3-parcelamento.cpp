#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int V, P;
    std::cin >> V >> P;

    int base = V / P;
    int resto = V % P;

    for (int i = 1; i <= P; i++) {
        if (i <= resto) {
            std::cout << base + 1 << std::endl;
        } else {
            std::cout << base << std::endl;
        }
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}