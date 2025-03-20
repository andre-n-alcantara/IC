#include <ctime>
#include <iostream>

int main() {
    int ano_atual;
    std::cin >> ano_atual;
    int ano_passagem = (ano_atual / 76 + 1) * 76;
    std::cout << ano_passagem << std::endl;
    
return 0;
}