#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int N, D, A;
    std::cin >> N >> D >> A;
    int diff = std::abs(D - A);
    int moves = std::min(diff, N - diff);
    std::cout << moves << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}