#include <iostream>

int main() {
    int N, D, A;
    std::cin >> N >> D >> A;
    int diff = std::abs(D - A);
    if (diff > N / 2) {
        diff = N - diff;
    }
    std::cout << diff << std::endl;
    return 0;
}