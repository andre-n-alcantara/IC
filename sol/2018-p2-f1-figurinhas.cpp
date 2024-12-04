#include <iostream>
#include <set>

int main() {
    int N, C, M;
    std::cin >> N >> C >> M;

    std::set<int> carimbadas;
    for (int i = 0; i < C; i++) {
        int x;
        std::cin >> x;
        carimbadas.insert(x);
    }

    std::set<int> compradas;
    for (int i = 0; i < M; i++) {
        int y;
        std::cin >> y;
        compradas.insert(y);
    }

    int faltam = 0;
    for (int x : carimbadas) {
        if (compradas.find(x) == compradas.end()) {
            faltam++;
        }
    }

    std::cout << faltam << std::endl;

    return 0;
}