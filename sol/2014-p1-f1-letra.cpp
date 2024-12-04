#include <iostream>
#include <string>
#include <cctype>

int main() {
    char letra;
    std::string texto;
    std::cin >> letra >> std::ws;
    std::getline(std::cin, texto);

    int contadorPalavrasComLetra = 0;
    int contadorPalavras = 0;
    bool palavraTemLetra = false;

    for (char c : texto) {
        if (std::isspace(c)) {
            if (palavraTemLetra) {
                contadorPalavrasComLetra++;
            }
            palavraTemLetra = false;
            contadorPalavras++;
        } else if (c == letra) {
            palavraTemLetra = true;
        }
    }

    if (palavraTemLetra) {
        contadorPalavrasComLetra++;
    }

    double porcentagem = static_cast<double>(contadorPalavrasComLetra) / contadorPalavras * 100.0;

    std::cout.precision(1);
    std::cout << std::fixed << porcentagem << std::endl;

    return 0;
}