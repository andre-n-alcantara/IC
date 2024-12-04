#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int heights[n];
    for (int i = 0; i < n; i++) {
        std::cin >> heights[i];
    }

    bool isEscher = true;
    for (int i = 0; i < n / 2; i++) {
        if (heights[i] + heights[n - i - 1] != heights[0] + heights[n - 1]) {
            isEscher = false;
            break;
        }
    }

    if (isEscher) {
        std::cout << "S" << std::endl;
    } else {
        std::cout << "N" << std::endl;
    }

    return 0;
}