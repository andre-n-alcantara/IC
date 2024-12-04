#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int insensibilidade = 0;

    for (int i = 0; i < N; i++) {
        int X1, Y1, X2, Y2;
        std::cin >> X1 >> Y1 >> X2 >> Y2;

        int dx = X2 - X1;
        int dy = Y2 - Y1;

        insensibilidade += dx * dx + dy * dy;
    }

    std::cout << insensibilidade << std::endl;

    return 0;
}