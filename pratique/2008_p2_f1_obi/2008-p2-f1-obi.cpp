#include <iostream>

int main() {
    int N, P, X, Y, count = 0;
    std::cin >> N >> P;
    for(int i = 0; i < N; i++) {
        std::cin >> X >> Y;
        if(X + Y >= P) count++;
    }
    std::cout << count << std::endl;
    return 0;
}