cpp
#include <iostream>

int minTests(int n, int k) {
    int low = 1, high = n, mid, ans = n;
    while (low <= high) {
        mid = (low + high) / 2;
        int tests = 1, left = mid - 1, right = n - mid;
        while (left > 0 || right > 0) {
            if (left > 0 && (left <= right || k == 1)) {
                left -= (mid - 1);
                tests++;
            } else {
                right -= mid;
                tests++;
            }
        }
        if (tests <= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::cout << minTests(n, k) << std::endl;
    return 0;
}
