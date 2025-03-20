#include <iostream>
#include <map>

int main() {
    int N;
    std::cin >> N;

    std::map<int, int> direita, esquerda;

    for (int i = 0; i < N; i++) {
        int M;
        char L;
        std::cin >> M >> L;

        if (L == 'D')
            direita[M]++;
        else
            esquerda[M]++;
    }

    int pares = 0;
    for (auto it = direita.begin(); it != direita.end(); it++) {
        pares += std::min(it->second, esquerda[it->first]);
    }

    std::cout << pares << std::endl;

    return 0;
}