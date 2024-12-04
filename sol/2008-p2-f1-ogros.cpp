#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> forces(N);
    for (int i = 0; i < N - 1; ++i) {
        std::cin >> forces[i];
    }

    std::vector<int> prizes(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> prizes[i];
    }

    std::vector<int> ogroForces(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> ogroForces[i];
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (ogroForces[i] < forces[j]) {
                std::cout << prizes[j - 1] << ' ';
                break;
            }
            if (j == N - 1) {
                std::cout << prizes[j] << ' ';
            }
        }
    }

    std::cout << std::endl;

    return 0;
}