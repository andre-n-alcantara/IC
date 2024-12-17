#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::cin >> N;

    int totalCoposQuebrados = 0;

    for (int i = 0; i < N; i++) {
        int L, C;
        std::cin >> L >> C;

        if (L > C) {
            totalCoposQuebrados += C;
        }
    }

    std::cout << totalCoposQuebrados << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}