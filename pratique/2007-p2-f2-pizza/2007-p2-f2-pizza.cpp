#include <ctime>
#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> diff(N);
    for (int i = 0; i < N; i++) {
        std::cin >> diff[i];
    }

    int max_sum = 0;
    int current_sum = 0;
    for (int i = 0; i < N; i++) {
        current_sum = 0;
        for (int j = i; j < N; j++) {
            current_sum += diff[j];
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
        for (int j = 0; j < i; j++) {
            current_sum += diff[j];
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }

    std::cout << max_sum << std::endl;

    
return 0;
}