#include <iostream>

int main() {
    int L, D, K, P;
    std::cin >> L >> D >> K >> P;
    int pedagios = (L + D - 1) / D;
    int custo_total = L * K + pedagios * P;
    std::cout << custo_total << std::endl;
    return 0;
}