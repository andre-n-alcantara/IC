#include <iostream>

int main() {
    int N, P, M;
    std::cin >> N;
    int pequeno = 0, medio = 0;
    for (int i = 0; i < N; i++) {
        int Ti;
        std::cin >> Ti;
        if (Ti == 1) pequeno++;
        else medio++;
    }
    std::cin >> P >> M;
    if (pequeno <= P && medio <= M) std::cout << "S" << std::endl;
    else std::cout << "N" << std::endl;
    return 0;
}