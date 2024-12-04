
#include <iostream>
#include <set>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::set<int> figurinhas;
    for (int i = 0; i < M; ++i) {
        int X;
        std::cin >> X;
        figurinhas.insert(X);
    }

    std::cout << N - figurinhas.size() << std::endl;

    return 0;
}
