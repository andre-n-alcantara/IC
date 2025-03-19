#include <ctime>
#include <iostream>
#include <set>

int main() {
    std::clock_t startTime = std::clock();
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

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}