
#include <iostream>
#include <string>

int main() {
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

    return 0;
}
