#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::cin >> N;
    int total = 1;
    for (int i = 0; i < N; i++) {
        int I;
        std::cin >> I;
        total = total * (I - 1);
    }
    std::cout << total << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}