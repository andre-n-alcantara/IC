#include <ctime>
#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;
    int P[N];
    P[0] = 0;
    for (int i = 1; i < N; i++) {
        std::cin >> P[i];
    }
    bool podeTerminar = true;
    for (int i = 0; i < N - 1; i++) {
        if (P[i + 1] - P[i] > M) {
            podeTerminar = false;
            break;
        }
    }
    if (42195 - P[N - 1] > M) {
        podeTerminar = false;
    }
    if (podeTerminar) {
        std::cout << "S" << std::endl;
    } else {
        std::cout << "N" << std::endl;
    }
    
return 0;
}