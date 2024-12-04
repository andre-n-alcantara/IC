
#include <iostream>

int main() {
    int N;
    std::cin >> N;

    long long max_bacteria = 0;
    int best_type = 0;

    for (int i = 0; i < N; i++) {
        int D, C;
        std::cin >> D >> C;

        long long bacteria = 1;
        for (int j = 0; j < C; j++) {
            bacteria *= D;
        }

        if (bacteria > max_bacteria) {
            max_bacteria = bacteria;
            best_type = i;
        }
    }

    std::cout << best_type << std::endl;

    return 0;
}
