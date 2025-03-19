#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int prev, curr, next;
    std::cin >> prev >> curr;

    bool hasMultiplePeaks = false;

    for (int i = 2; i < N; i++) {
        std::cin >> next;
        if (prev > curr && curr < next) {
            hasMultiplePeaks = true;
            break;
        }
        prev = curr;
        curr = next;
    }

    std::cout << (hasMultiplePeaks ? "S" : "N") << std::endl;

    return 0;
}