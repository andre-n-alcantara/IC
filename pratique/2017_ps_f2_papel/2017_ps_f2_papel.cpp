#include <iostream>
#include <vector>

int cortarPapel(int n, const std::vector<int>& alturas) {
    int maxCortes = 0;
    for (int i = 1; i < n; ++i) {
        int cortes = 1;
        int altura = alturas[i - 1];
        for (int j = i; j < n; ++j) {
            if (alturas[j] != altura) {
                ++cortes;
                altura = alturas[j];
            }
        }
        maxCortes = std::max(maxCortes, cortes);
    }
    return maxCortes;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> alturas(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> alturas[i];
    }
    std::cout << cortarPapel(n, alturas) << std::endl;
    return 0;
}