#include <ctime>
#include <iostream>
#include <cmath>

int main() {
    std::clock_t startTime = std::clock();
    int L, A, P, R;
    while (std::cin >> L >> A >> P >> R) {
        double radius = std::sqrt(std::pow(L, 2) + std::pow(A, 2) + std::pow(P, 2));
        if (radius <= R) {
            std::cout << "S" << std::endl;
        } else {
            std::cout << "N" << std::endl;
        }
    }
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}