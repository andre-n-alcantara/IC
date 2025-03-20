#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> heights[i];
    }
    int max_height = *std::max_element(heights.begin(), heights.end());
    int max_distance = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            max_distance = std::max(max_distance, heights[i] + j - i + heights[j]);
        }
    }
    std::cout << max_distance << std::endl;
    
return 0;
}