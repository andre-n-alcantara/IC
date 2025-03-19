#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::cin >> N;
    std::vector<int> houses(N);
    for (int i = 0; i < N; i++) {
        std::cin >> houses[i];
    }
    int K;
    std::cin >> K;

    int left = 0;
    int right = N - 1;
    while (left < right) {
        int sum = houses[left] + houses[right];
        if (sum == K) {
            std::cout << houses[left] << " " << houses[right] << std::endl;
            
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
        } else if (sum < K) {
            left++;
        } else {
            right--;
        }
    }

    return 0;
}