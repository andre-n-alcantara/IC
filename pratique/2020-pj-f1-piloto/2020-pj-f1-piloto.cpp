#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int A, B, C;
    std::cin >> A >> B >> C;

    if (B - A < C - B) {
        std::cout << 1 << std::endl;
    } else if (B - A > C - B) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}