#include <ctime>
#include <iostream>

int somaDigitos(int n) {
    int soma = 0;
    while (n > 0) {
        soma += n % 10;
        n /= 10;
    }
    return soma;
}

int main() {
    int S, A, B;
    std::cin >> S >> A >> B;
    int count = 0;
    for (int i = A; i <= B; i++) {
        if (somaDigitos(i) == S) {
            count++;
        }
    }
    std::cout << count << std::endl;
    
return 0;
}