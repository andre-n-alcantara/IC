#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int M, A, B;
    std::cin >> M >> A >> B;
    int C = M - A - B;
    if (A > B && A > C) {
        std::cout << A << std::endl;
    } else if (B > A && B > C) {
        std::cout << B << std::endl;
    } else {
        std::cout << C << std::endl;
    }
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}