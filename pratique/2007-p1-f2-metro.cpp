#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::clock_t startTime = std::clock();
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
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}