#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int sum = n * (n + 1) / 2;
    int current_sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int num;
        std::cin >> num;
        current_sum += num;
    }
    std::cout << sum - current_sum << std::endl;
    return 0;
}