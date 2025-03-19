#include <iostream>
#include <set>

int main() {
    int N, C, M;
    std::cin >> N >> C >> M;

    std::set<int> carimbadas;
    for (int i = 0; i < C; i++) {
        int xi;
        std::cin >> xi;
        carimbadas.insert(xi);
    }

    std::set<int> compradas;
    for (int i = 0; i < M; i++) {
        int yi;
        std::cin >> yi;
        compradas.insert(yi);
    }

    int faltam = 0;
    for (int xi : carimbadas) {
        if (compradas.find(xi) == compradas.end()) {
            faltam++;
        }
    }

    std::cout << faltam << std::endl;

    return 0;
}