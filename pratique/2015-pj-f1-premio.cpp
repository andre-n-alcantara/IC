#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int n, acc, total = 0, days = 0;
    std::cin >> n;
    while(n--) {
        std::cin >> acc;
        total += acc;
        days++;
        if(total >= 1000000) break;
    }
    std::cout << days << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}