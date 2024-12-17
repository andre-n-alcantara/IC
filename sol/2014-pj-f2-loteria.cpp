#include <ctime>
#include <iostream>
#include <algorithm>

int main() {
    std::clock_t startTime = std::clock();
    int flavinho[6], sorteio[6];
    for (int i = 0; i < 6; i++) {
        std::cin >> flavinho[i];
    }
    for (int i = 0; i < 6; i++) {
        std::cin >> sorteio[i];
    }

    int acertos = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (flavinho[i] == sorteio[j]) {
                acertos++;
                break;
            }
        }
    }

    if (acertos < 3) {
        std::cout << "azar" << std::endl;
    } else if (acertos == 3) {
        std::cout << "terno" << std::endl;
    } else if (acertos == 4) {
        std::cout << "quadra" << std::endl;
    } else if (acertos == 5) {
        std::cout << "quina" << std::endl;
    } else {
        std::cout << "sena" << std::endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}