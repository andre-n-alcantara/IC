#include <ctime>
#include <iostream>
#include <string>

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::string gabarito, respostas;

    std::cin >> N;
    std::cin >> gabarito >> respostas;

    int acertos = 0;
    for (int i = 0; i < N; i++) {
        if (gabarito[i] == respostas[i]) {
            acertos++;
        }
    }

    std::cout << acertos << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}