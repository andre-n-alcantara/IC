#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> piles;
    for (int i = 0; i < N; ++i) {
        int height;
        std::cin >> height;
        piles.push_back(height);
    }

    std::sort(piles.begin(), piles.end());

    int steps = 0;
    for (int i = 0; i < N - 1; ++i) {
        steps += piles[i + 1] - piles[i] - 1;
    }

    if (piles[0] + steps != piles[N - 1]) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << steps << std::endl;
    }

    return 0;
}