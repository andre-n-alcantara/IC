#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int E1, E2, E3, X;
    std::cin >> E1 >> E2 >> E3 >> X;
    if (E2 - E1 <= X) {
        std::cout << E2 << std::endl;
    } else {
        std::cout << E3 << std::endl;
    }
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}