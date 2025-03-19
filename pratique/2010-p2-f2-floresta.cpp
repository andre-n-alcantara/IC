#include <ctime>
#include <iostream>

int countArrangements(int n) {
    int count = 0;
    for (int x = 1; x * x <= n; x++) {
        if (n % (x + 1) == 0 && (n / (x + 1)) >= x) {
            count++;
        }
    }
    return count;
}

int main() {
    std::clock_t startTime = std::clock();
    int n;
    std::cin >> n;
    std::cout << countArrangements(n) << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}