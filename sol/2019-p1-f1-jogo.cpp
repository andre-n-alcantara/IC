#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int total = (n * (n + 1) * (n * 2 + 1)) / 6;
    std::cout << total << std::endl;
    return 0;
}