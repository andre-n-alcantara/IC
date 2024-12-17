#include <ctime>
#include <iostream>
#include <algorithm>

int main() {
    std::clock_t startTime = std::clock();
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::vector<int> levels = {a, b, c, d};
    std::sort(levels.begin(), levels.end());
    int sum1 = levels[0] + levels[3];
    int sum2 = levels[1] + levels[2];
    std::cout << std::abs(sum1 - sum2) << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}