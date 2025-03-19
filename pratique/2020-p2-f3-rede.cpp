#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> repostagens(N);
    for (int i = 0; i < N; i++) {
        std::cin >> repostagens[i];
    }

    std::sort(repostagens.begin(), repostagens.end());

    int influencia = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (repostagens[i] >= influencia + 1) {
            influencia++;
        }
    }

    std::cout << influencia << std::endl;

    return 0;
}