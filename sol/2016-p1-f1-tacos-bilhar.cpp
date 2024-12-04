#include <iostream>
#include <set>

int main() {
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
    return 0;
}