#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> prices(N);
    for (int i = 0; i < N; i++) {
        std::cin >> prices[i];
    }
    std::sort(prices.begin(), prices.end());
    int total = 0;
    for (int i = N - 1; i >= 0; i -= 2) {
        total += prices[i];
        if (i > 0) {
            total += prices[i - 1];
        }
    }
    std::cout << total << std::endl;
    return 0;
}