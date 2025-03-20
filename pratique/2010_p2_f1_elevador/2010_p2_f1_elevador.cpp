#include <ctime>
#include <iostream>

int main() {
    int N, C;
    std::cin >> N >> C;

    int pessoas_dentro = 0;
    bool excedido = false;

    for (int i = 0; i < N; ++i) {
        int S, E;
        std::cin >> S >> E;

        pessoas_dentro -= S;
        pessoas_dentro += E;

        if (pessoas_dentro > C) {
            excedido = true;
            break;
        }
    }

    std::cout << (excedido ? "S" : "N") << std::endl;

    
return 0;
}