#include <iostream>
#include <algorithm>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::vector<int> levels = {a, b, c, d};
    std::sort(levels.begin(), levels.end());
    int sum1 = levels[0] + levels[3];
    int sum2 = levels[1] + levels[2];
    std::cout << std::abs(sum1 - sum2) << std::endl;
    return 0;
}