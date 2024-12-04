#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> rotulos(N);
    for (int i = 0; i < N; i++) {
        std::cin >> rotulos[i];
    }

    int envelopes = INT_MAX;
    for (int i = 0; i < N; i++) {
        envelopes = std::min(envelopes, rotulos[i]);
    }

    std::cout << envelopes << std::endl;

    return 0;
}