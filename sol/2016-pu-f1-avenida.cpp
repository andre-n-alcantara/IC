
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> grid(N, std::vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> grid[i][j];
        }
    }

    int min_cost = INT_MAX;
    for (int i = 0; i < M; ++i) {
        int cost = 0;
        for (int j = 0; j < N; ++j) {
            cost += grid[j][i];
        }
        min_cost = std::min(min_cost, cost);
    }

    std::cout << min_cost << std::endl;

    return 0;
}
