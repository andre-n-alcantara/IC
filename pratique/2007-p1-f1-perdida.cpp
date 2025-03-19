#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int n;
    std::cin >> n;
    int sum = n * (n + 1) / 2;
    int current_sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int num;
        std::cin >> num;
        current_sum += num;
    }
    std::cout << sum - current_sum << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}