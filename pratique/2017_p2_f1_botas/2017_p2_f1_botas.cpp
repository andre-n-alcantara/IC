#include <ctime>
#include <iostream>
#include <map>

int main() {
    int N;
    std::cin >> N;

    std::map<int, int> dir, esq;
    for (int i = 0; i < N; i++) {
        int M;
        char L;
        std::cin >> M >> L;

        if (L == 'D')
            dir[M]++;
        else
            esq[M]++;
    }

    int pares = 0;
    for (auto it = dir.begin(); it != dir.end(); it++) {
        pares += std::min(it->second, esq[it->first]);
    }

    std::cout << pares << std::endl;

    
return 0;
}