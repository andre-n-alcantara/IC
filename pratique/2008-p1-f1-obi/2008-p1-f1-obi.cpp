#include <iostream>

int main() {
    int N, P;
    std::cin >> N >> P;

    int count = 0;
    for (int i = 0; i < N; i++) {
        int X, Y;
        std::cin >> X >> Y;
        if (X + Y >= P) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}