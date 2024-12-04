#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> rooms(N);
    for (int i = 0; i < N; i++) {
        std::cin >> rooms[i];
    }
    int max_lives = 0, curr_lives = 0;
    for (int i = 0; i < N; i++) {
        curr_lives += rooms[i];
        max_lives = std::max(max_lives, curr_lives);
        if (curr_lives < 0) {
            curr_lives = 0;
        }
    }
    std::cout << max_lives << std::endl;
    return 0;
}