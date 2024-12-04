
#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int substituir = 0, consertar = 0;
    for (int i = 0; i < N; i++) {
        int tamanho;
        std::cin >> tamanho;
        if (tamanho < 50) {
            substituir++;
        } else if (tamanho < 85) {
            consertar++;
        }
    }

    std::cout << substituir << " " << consertar << std::endl;

    return 0;
}
