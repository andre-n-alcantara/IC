#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    long long int N;
    std::cin >> N;

    for (long long int i = 2; i * i <= N; ++i) {
        if (N % i == 0) {
            std::cout << "S" << std::endl;
            
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
        }
    }

    std::cout << "N" << std::endl;
    return 0;
}