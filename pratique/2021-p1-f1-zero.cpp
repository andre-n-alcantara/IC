#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int n;
    std::cin >> n;
    int sum = 0;
    int last = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> last;
        if (last != 0) {
            sum += last;
        } else {
            sum -= last;
        }
    }
    std::cout << sum << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}