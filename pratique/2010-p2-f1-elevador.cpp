#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
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

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}