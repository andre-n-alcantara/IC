
#include <iostream>

int main() {
    int n, acc, total = 0, days = 0;
    std::cin >> n;
    while(n--) {
        std::cin >> acc;
        total += acc;
        days++;
        if(total >= 1000000) break;
    }
    std::cout << days << std::endl;
    return 0;
}
