#include <iostream>

int main() {
    int N, P, M, countP = 0, countM = 0;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int Ti;
        std::cin >> Ti;
        if (Ti == 1) countP++;
        else countM++;
    }
    std::cin >> P >> M;
    if (countP <= P && countM <= M) std::cout << "S";
    else std::cout << "N";
    return 0;
}