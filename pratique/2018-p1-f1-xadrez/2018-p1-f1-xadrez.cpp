#include <ctime>
#include <iostream>

int main() {
    int L, C;
    std::cin >> L >> C;
    std::cout << ((L + C) % 2 ? 0 : 1) << std::endl;
    
return 0;
}