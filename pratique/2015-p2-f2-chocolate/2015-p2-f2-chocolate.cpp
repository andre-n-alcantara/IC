#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int N, X_1, Y_1, X_2, Y_2;
    std::cin >> N >> X_1 >> Y_1 >> X_2 >> Y_2;

    if ((X_1 + X_2 == N + 1) || (Y_1 + Y_2 == N + 1))
        std::cout << "S" << std::endl;
    else
        std::cout << "N" << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}