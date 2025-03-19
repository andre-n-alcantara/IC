#include <ctime>
#include <iostream>
#include <string>

int main() {
    std::clock_t startTime = std::clock();
    int I, N;
    std::cin >> I >> N;

    int dalia = I, eloi = I, felix = I;

    char op;
    char jogador;
    int valor;
    char jogador2;

    for (int i = 0; i < N; i++) {
        std::cin >> op >> jogador >> valor;

        if (op == 'C') {
            if (jogador == 'D') dalia -= valor;
            else if (jogador == 'E') eloi -= valor;
            else felix -= valor;
        } else if (op == 'V') {
            if (jogador == 'D') dalia += valor;
            else if (jogador == 'E') eloi += valor;
            else felix += valor;
        } else if (op == 'A') {
            std::cin >> jogador2 >> valor;

            if (jogador == 'D') dalia += valor;
            else if (jogador == 'E') eloi += valor;
            else felix += valor;

            if (jogador2 == 'D') dalia -= valor;
            else if (jogador2 == 'E') eloi -= valor;
            else felix -= valor;
        }
    }

    std::cout << dalia << " " << eloi << " " << felix << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}