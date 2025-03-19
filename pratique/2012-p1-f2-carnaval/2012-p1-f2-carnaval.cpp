#include <ctime>
#include <iostream>
#include <algorithm>

int main() {
    std::clock_t startTime = std::clock();
    double n[5];
    for (int i = 0; i < 5; i++) {
        std::cin >> n[i];
    }
    std::sort(n, n + 5);
    std::cout << std::fixed << std::setprecision(1) << n[1] + n[2] + n[3] << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}