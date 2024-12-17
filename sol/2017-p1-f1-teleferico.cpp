#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int C, A;
    std::cin >> C >> A;

    int viagens = (A + C - 1) / C;

    std::cout << viagens << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}