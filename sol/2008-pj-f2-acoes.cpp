
#include <iostream>
#include <vector>

int main() {
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

    return 0;
}
