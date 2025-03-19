#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::clock_t startTime = std::clock();
    int N, M;
    std::cin >> N >> M;
    std::vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> heights[i];
    }

    int moves = 0;
    for (int i = 0; i < N; ++i) {
        moves += std::abs(heights[i] - M);
    }

    std::cout << moves << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}