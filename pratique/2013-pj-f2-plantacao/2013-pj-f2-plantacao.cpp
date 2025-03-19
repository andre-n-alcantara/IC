#include <ctime>
#include <iostream>
#include <vector>
#include <string>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> trees(K);
    for (int i = 0; i < K; i++) {
        std::cin >> trees[i];
    }

    std::string weather;
    std::cin >> weather;

    int totalFruits = 0;
    for (int i = 0; i < N; i++) {
        char w = weather[i % weather.size()];
        for (int j = 0; j < K; j++) {
            if (trees[j] > 0) {
                if (w == 'C') {
                    trees[j]++;
                } else {
                    trees[j]--;
                }
                if (trees[j] > 0) {
                    totalFruits++;
                }
            }
        }
    }

    std::cout << totalFruits << std::endl;

    
return 0;
}