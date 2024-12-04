
#include <iostream>

int main() {
    int N, P, X, Y, cont = 0;
    std::cin >> N >> P;
    for(int i = 0; i < N; i++) {
        std::cin >> X >> Y;
        if(X + Y >= P) cont++;
    }
    std::cout << cont << std::endl;
    return 0;
}
