#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> quadras(N, std::vector<int>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> quadras[i][j];
        }
    }

    int min_valor = INT_MAX;

    for (int j = 0; j < M; ++j) {
        int soma = 0;
        for (int i = 0; i < N; ++i) {
            soma += quadras[i][j];
        }
        min_valor = std::min(min_valor, soma);
    }

    std::cout << min_valor << std::endl;

    return 0;
}