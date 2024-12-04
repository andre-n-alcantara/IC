#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, s;
    std::cin >> n >> s;
    std::vector<int> movements(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> movements[i];
    }
    int min_balance = s;
    for (int i = 0; i < n; ++i) {
        s += movements[i];
        min_balance = std::min(min_balance, s);
    }
    std::cout << min_balance << std::endl;
    return 0;
}