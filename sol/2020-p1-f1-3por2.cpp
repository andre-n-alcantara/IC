#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> chocolates(N);
    for (int i = 0; i < N; i++) {
        std::cin >> chocolates[i];
    }
    std::sort(chocolates.begin(), chocolates.end(), std::greater<int>());
    int total = 0;
    for (int i = 0; i < N; i += 3) {
        total += chocolates[i];
        if (i + 1 < N) {
            total += chocolates[i + 1];
        }
    }
    std::cout << total << std::endl;
    return 0;
}