#include <iostream>
#include <vector>
#include <algorithm>

int main() {
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
    return 0;
}