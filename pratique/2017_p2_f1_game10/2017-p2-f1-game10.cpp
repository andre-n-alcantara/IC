#include <ctime>
#include <iostream>

int main() {
    int N, D, A;
    std::cin >> N >> D >> A;
    int diff = std::abs(D - A);
    int moves = std::min(diff, N - diff);
    std::cout << moves << std::endl;
    
return 0;
}