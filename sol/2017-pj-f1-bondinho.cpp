#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int A, M;
    std::cin >> A >> M;
    if (A + M <= 50) {
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