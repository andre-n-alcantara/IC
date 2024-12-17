#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::cin >> N;

    int insensibilidade = 0;

    for (int i = 0; i < N; i++) {
        int X1, Y1, X2, Y2;
        std::cin >> X1 >> Y1 >> X2 >> Y2;

        int dx = X2 - X1;
        int dy = Y2 - Y1;

        insensibilidade += dx * dx + dy * dy;
    }

    std::cout << insensibilidade << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}