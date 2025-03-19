#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, L, R;
    std::cin >> N >> L >> R;
    std::vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        std::cin >> nums[i];
    }
    std::sort(nums.begin(), nums.end());
    int max_diff = 0;
    for (int i = 0; i < N; i++) {
        int diff = std::max(L - nums[i], nums[i] - R);
        max_diff = std::max(max_diff, diff);
    }
    std::cout << max_diff << std::endl;
    return 0;
}