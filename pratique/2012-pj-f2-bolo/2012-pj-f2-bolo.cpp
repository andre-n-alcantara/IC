#include <ctime>
#include <iostream>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;
    int bolos = (A / 2) < (B / 3) ? (A / 2) < (C / 5) ? A / 2 : C / 5 : (B / 3) < (C / 5) ? B / 3 : C / 5;
    std::cout << bolos << std::endl;
    
return 0;
}