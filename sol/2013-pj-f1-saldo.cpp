#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::clock_t startTime = std::clock();
    int n, s;
    std::cin >> n >> s;
    std::vector<int> movements(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> movements[i];
    }
    int min_balance = s;
    for (int i = 0; i < n; ++i) {
        s += movements[i];
        min_balance = std::min(min_balance, s);
    }
    std::cout << min_balance << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}