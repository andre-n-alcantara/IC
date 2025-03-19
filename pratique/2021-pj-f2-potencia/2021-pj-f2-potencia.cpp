#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int n;
    std::cin >> n;

    long long sum = 0;
    for(int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        int base = t / 10;
        int exp = t % 10;
        long long result = 1;
        for(int j = 0; j < exp; j++) {
            result *= base;
        }
        sum += result;
    }

    std::cout << sum << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}