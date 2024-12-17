#include <ctime>
#include <iostream>
#include <string>

int main() {
    std::clock_t startTime = std::clock();
    std::string mensagem;
    std::getline(std::cin, mensagem);

    int divertido = 0, chateado = 0;

    for (char c : mensagem) {
        if (c == ':' && mensagem.find(":-)", mensagem.find(c)) != std::string::npos) {
            divertido++;
        } else if (c == ':' && mensagem.find(":/-", mensagem.find(c)) != std::string::npos) {
            chateado++;
        }
    }

    if (divertido > chateado) {
        std::cout << "divertido";
    } else if (divertido < chateado) {
        std::cout << "chateado";
    } else {
        std::cout << "neutro";
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}