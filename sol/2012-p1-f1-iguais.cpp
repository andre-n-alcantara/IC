#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> values(N);
    for (int i = 0; i < N; i++) {
        std::cin >> values[i];
    }

    int max_points = 0, current_points = 1;
    for (int i = 1; i < N; i++) {
        if (values[i] == values[i - 1]) {
            current_points++;
            max_points = std::max(max_points, current_points);
        } else {
            current_points = 1;
        }
    }

    std::cout << max_points << std::endl;
    return 0;
}