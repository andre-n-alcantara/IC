
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, L, R;
    std::cin >> N >> L >> R;
    std::vector<int> papers(N);
    for (int i = 0; i < N; i++) {
        std::cin >> papers[i];
    }
    int minimax = 0;
    for (int i = L; i <= R; i++) {
        int min_diff = INT_MAX;
        for (int j = 0; j < N; j++) {
            int diff = std::abs(papers[j] - i);
            if (diff < min_diff) {
                min_diff = diff;
            }
        }
        if (min_diff > minimax) {
            minimax = min_diff;
        }
    }
    std::cout << minimax << std::endl;
    return 0;
}
