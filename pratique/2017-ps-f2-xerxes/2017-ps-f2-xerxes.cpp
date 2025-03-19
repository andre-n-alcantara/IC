#include <iostream>

int main() {
    int N, winsDario = 0, winsXerxes = 0;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int D, X;
        std::cin >> D >> X;

        if ((D == 0 && X == 3) || (D == 1 && X == 4) || (D == 2 && X == 0) ||
            (D == 3 && X == 1) || (D == 4 && X == 2)) {
            winsXerxes++;
        } else {
            winsDario++;
        }
    }

    if (winsDario > winsXerxes) {
        std::cout << "dario" << std::endl;
    } else {
        std::cout << "xerxes" << std::endl;
    }

    return 0;
}