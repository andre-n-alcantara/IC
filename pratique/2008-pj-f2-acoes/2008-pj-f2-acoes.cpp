#include <ctime>
#include <iostream>
#include <vector>

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::cin >> N;
    std::vector<int> variations(N);
    for (int i = 0; i < N; i++) {
        std::cin >> variations[i];
    }

    int max_profit = 0;
    for (int i = 0; i <= N - 4; i++) {
        int profit = 0;
        for (int j = i; j < i + 4; j++) {
            profit += variations[j];
        }
        if (profit > max_profit) {
            max_profit = profit;
        }
    }

    std::cout << max_profit << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}