#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::cin >> N;

    if (N <= 5) {
        for (int i = 0; i < N; i++) {
            std::cout << "I";
        }
        std::cout << std::endl;
        std::cout << "*" << std::endl;
    } else {
        for (int i = 0; i < 5; i++) {
            std::cout << "I";
        }
        std::cout << std::endl;
        for (int i = 0; i < N - 5; i++) {
            std::cout << "I";
        }
        std::cout << std::endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}