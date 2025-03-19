#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int L;
    std::cin >> L;
    int pedacos = 1;
    while (L >= 2) {
        pedacos *= 4;
        L /= 2;
    }
    std::cout << pedacos << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}