#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int A, N;
    std::cin >> A >> N;
    std::cout << (A / (N + 1)) * 2 << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}