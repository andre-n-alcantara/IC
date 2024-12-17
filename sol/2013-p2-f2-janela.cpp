#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int F1, F2, F3;
    std::cin >> F1 >> F2 >> F3;

    int area = 0;
    if (F1 < F2) area += F2 - F1;
    if (F2 < F3) area += F3 - F2;

    std::cout << area * 100 << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}