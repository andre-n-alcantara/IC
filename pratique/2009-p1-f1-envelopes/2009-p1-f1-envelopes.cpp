#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> labels(N);
    for (int i = 0; i < N; i++) {
        std::cin >> labels[i];
    }

    std::vector<int> count(K + 1, 0);
    for (int i = 0; i < N; i++) {
        count[labels[i]]++;
    }

    int min_labels = N;
    for (int i = 1; i <= K; i++) {
        min_labels = std::min(min_labels, count[i]);
    }

    std::cout << min_labels << std::endl;

    
return 0;
}