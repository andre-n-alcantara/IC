#include <ctime>
#include <iostream>
#include <vector>

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::cin >> N;
    std::vector<int> sections(N);
    for (int i = 0; i < N; i++) {
        std::cin >> sections[i];
    }

    int left = 0, right = 0;
    for (int i = 0; i < N; i++) {
        right += sections[i];
    }

    for (int i = 0; i < N; i++) {
        left += sections[i];
        right -= sections[i];
        if (left == right) {
            std::cout << i + 1 << std::endl;
            
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
        }
    }

    return 0;
}