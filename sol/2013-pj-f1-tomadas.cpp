
#include <iostream>

int main() {
    int T1, T2, T3, T4;
    std::cin >> T1 >> T2 >> T3 >> T4;
    int total = 1;
    total += T1 - 1;
    total += T2 - 1;
    total += T3 - 1;
    total += T4 - 1;
    std::cout << total << std::endl;
    return 0;
}
