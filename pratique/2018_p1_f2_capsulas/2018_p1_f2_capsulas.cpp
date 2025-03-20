#include <iostream>
#include <vector>

int main() {
    int N, F;
    std::cin >> N >> F;
    std::vector<int> cycles(N);
    for (int i = 0; i < N; i++) {
        std::cin >> cycles[i];
    }

    long long totalDays = 0;
    long long totalCoins = 0;
    while (totalCoins < F) {
        int nextCycle = 0;
        for (int i = 0; i < N; i++) {
            if (cycles[i] <= nextCycle || nextCycle == 0) {
                nextCycle = cycles[i];
            }
        }
        totalDays += nextCycle;
        totalCoins += N;
    }

    std::cout << totalDays << std::endl;
    return 0;
}