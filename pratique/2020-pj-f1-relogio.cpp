#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int R, F, C;
    std::cin >> R >> F >> C;

    if (F > 3 * R || C < 95) {
        std::cout << "diminuir" << std::endl;
    } else if (F < 2 * R && C > 97) {
        std::cout << "aumentar" << std::endl;
    } else {
        std::cout << "manter" << std::endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}