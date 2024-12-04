
#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int totalCoposQuebrados = 0;

    for (int i = 0; i < N; i++) {
        int L, C;
        std::cin >> L >> C;

        if (L > C) {
            totalCoposQuebrados += C;
        }
    }

    std::cout << totalCoposQuebrados << std::endl;

    return 0;
}
