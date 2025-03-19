#include <ctime>
#include <iostream>
#include <set>

int main() {
    std::clock_t startTime = std::clock();
    int N, M;
    std::cin >> N >> M;

    std::set<int> figurinhas;
    for (int i = 0; i < M; ++i) {
        int X;
        std::cin >> X;
        figurinhas.insert(X);
    }

    std::cout << N - figurinhas.size() << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}