#include <iostream>

int main() {
    int M, A, B;
    std::cin >> M >> A >> B;
    int idadeFilhoMaisVelho = M - A - B;
    if (idadeFilhoMaisVelho > A && idadeFilhoMaisVelho > B) {
        std::cout << idadeFilhoMaisVelho << std::endl;
    } else if (A > idadeFilhoMaisVelho && A > B) {
        std::cout << A << std::endl;
    } else {
        std::cout << B << std::endl;
    }
    return 0;
}