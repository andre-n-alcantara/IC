#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int ano_atual;
    std::cin >> ano_atual;
    int ano_passagem = (ano_atual / 76 + 1) * 76;
    std::cout << ano_passagem << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}