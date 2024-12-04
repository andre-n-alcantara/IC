#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int sum = 0;
    int last = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> last;
        if (last != 0) {
            sum += last;
        } else {
            sum -= last;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}