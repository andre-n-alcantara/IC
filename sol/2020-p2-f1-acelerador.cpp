
#include <iostream>

int main() {
    int d;
    std::cin >> d;
    int dist_emissor_acelerador = 3;
    int circunferencia_acelerador = 8;

    if(d <= dist_emissor_acelerador + circunferencia_acelerador) {
        std::cout << 1 << std::endl;
    } else if((d - dist_emissor_acelerador) % circunferencia_acelerador == 0) {
        std::cout << 2 << std::endl;
    } else {
        std::cout << 3 << std::endl;
    }

    return 0;
}
