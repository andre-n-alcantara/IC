#include <iostream>

int main() {
    int V, P;
    std::cin >> V >> P;

    int valor_parcela = V / P;
    int resto = V % P;

    for (int i = 1; i <= P; i++) {
        if (i <= resto) {
            std::cout << valor_parcela + 1 << std::endl;
        } else {
            std::cout << valor_parcela << std::endl;
        }
    }

    return 0;
}