#include <ctime>
#include <iostream>
#include <vector>

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::cin >> N;
    std::vector<int> times(N);
    for (int i = 0; i < N; i++) {
        std::cin >> times[i];
    }

    int timeOn = 0;
    int lastTime = -10; // inicialmente, a escada rolante estava desligada

    for (int i = 0; i < N; i++) {
        if (times[i] - lastTime > 10) {
            timeOn += 10;
        } else {
            timeOn += times[i] - lastTime;
        }
        lastTime = times[i];
    }

    timeOn += 10; // acrescenta os últimos 10 segundos

    std::cout << timeOn << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}