
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> houses(N);
    for (int i = 0; i < N; i++) {
        std::cin >> houses[i];
    }
    int K;
    std::cin >> K;

    int left = 0;
    int right = N - 1;
    while (left < right) {
        int sum = houses[left] + houses[right];
        if (sum == K) {
            std::cout << houses[left] << " " << houses[right] << std::endl;
            return 0;
        } else if (sum < K) {
            left++;
        } else {
            right--;
        }
    }

    return 0;
}
