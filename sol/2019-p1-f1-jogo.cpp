#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int n;
    std::cin >> n;
    int total = (n * (n + 1) * (n * 2 + 1)) / 6;
    std::cout << total << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}