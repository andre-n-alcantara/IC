
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> pao(K);
    for (int i = 0; i < K; i++) {
        std::cin >> pao[i];
    }
    int maxFatia = 0;
    for (int i = 1; i <= *std::max_element(pao.begin(), pao.end()); i++) {
        int cnt = 0;
        for (int j = 0; j < K; j++) {
            cnt += pao[j] / i;
        }
        if (cnt >= N) {
            maxFatia = i;
        }
    }
    std::cout << maxFatia << std::endl;
    return 0;
}
