#include <ctime>
#include <iostream>

int main() {
    int F, C, E, B;
    std::cin >> F >> C >> E >> B;

    int totalAssentosEcon = (F - E + 1) * C;
    if (B > totalAssentosEcon) {
        std::cout << "PROXIMO VOO" << std::endl;
    } else {
        int fileira = E - 1 + (B - 1) / C;
        char posicao = 'A' + (B - 1) % C;
        std::cout << fileira << " " << posicao << std::endl;
    }

    
return 0;
}