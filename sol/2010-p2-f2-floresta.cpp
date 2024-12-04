#include <iostream>

int countArrangements(int n) {
    int count = 0;
    for (int x = 1; x * x <= n; x++) {
        if (n % (x + 1) == 0 && (n / (x + 1)) >= x) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << countArrangements(n) << std::endl;
    return 0;
}