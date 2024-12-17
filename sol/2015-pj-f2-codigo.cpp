#include <ctime>
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::clock_t startTime = std::clock();
    int n;
    std::cin >> n;
    std::vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        std::cin >> seq[i];
    }
    int count = 0;
    for (int i = 0; i < n - 2; i++) {
        if (seq[i] == 1 && seq[i + 1] == 0 && seq[i + 2] == 0) {
            count++;
        }
    }
    std::cout << count << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}