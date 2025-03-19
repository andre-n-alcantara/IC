#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> numbers;
    for (int i = 0; i < N; i++) {
        int num;
        std::cin >> num;
        if (num == 0) {
            if (!numbers.empty()) {
                numbers.pop_back();
            }
        } else {
            numbers.push_back(num);
        }
    }
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    std::cout << sum << std::endl;
    return 0;
}