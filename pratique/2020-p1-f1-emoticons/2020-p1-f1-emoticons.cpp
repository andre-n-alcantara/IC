#include <ctime>
#include <iostream>
#include <string>

int main() {
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

    
return 0;
}