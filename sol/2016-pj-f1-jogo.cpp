#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int P, D_1, D_2;
    std::cin >> P >> D_1 >> D_2;

    int sum = D_1 + D_2;
    if ((sum % 2 == 0 && P == 0) || (sum % 2 != 0 && P == 1)) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << 1 << std::endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}