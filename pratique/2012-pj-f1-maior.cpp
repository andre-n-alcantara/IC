#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int maior = 0, num;
    while (true) {
        std::cin >> num;
        if (num == 0) break;
        if (num > maior) maior = num;
    }
    std::cout << maior << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}