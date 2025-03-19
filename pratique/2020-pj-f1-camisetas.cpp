#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int N, P, M, countP = 0, countM = 0;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int Ti;
        std::cin >> Ti;
        if (Ti == 1) countP++;
        else countM++;
    }
    std::cin >> P >> M;
    if (countP <= P && countM <= M) std::cout << "S";
    else std::cout << "N";
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}