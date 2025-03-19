#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int P, R;
    std::cin >> P >> R;

    if (P == 1 && R == 0) {
        std::cout << "B" << std::endl;
    } else if (P == 0 && R == 0) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "A" << std::endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}