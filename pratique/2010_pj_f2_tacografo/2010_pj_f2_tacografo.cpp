#include <ctime>
#include <iostream>

int main() {
    int N;
    std::cin >> N;

    long long distancia = 0;

    for (int i = 0; i < N; i++) {
        int T, V;
        std::cin >> T >> V;
        distancia += T * V;
    }

    std::cout << distancia << std::endl;

    
return 0;
}