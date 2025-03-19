#include <ctime>
#include <iostream>
#include <set>

int main() {
    std::clock_t startTime = std::clock();
    int C;
    std::cin >> C;
    std::set<int> estoque;
    int total_tacos = 0;
    for (int i = 0; i < C; i++) {
        int comprimento;
        std::cin >> comprimento;
        if (estoque.find(comprimento) == estoque.end()) {
            estoque.insert(comprimento);
            total_tacos += 2; // faz duas cópias
        } else {
            total_tacos++; // só envia um taco
        }
    }
    std::cout << total_tacos << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}