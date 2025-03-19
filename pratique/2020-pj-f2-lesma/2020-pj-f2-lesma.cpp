#include <ctime>
#include <iostream>

int main() {
    int A, S, D;
    std::cin >> A >> S >> D;
    int days = (A + D - 1) / (S - D);
    std::cout << days << std::endl;
    
return 0;
}