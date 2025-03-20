#include <iostream>

int main() {
    int IA, IB, FA, FB;
    std::cin >> IA >> IB >> FA >> FB;

    int changes = 0;
    if (IA != FA) changes++;
    if (IB != FB) {
        if (changes == 0) changes = 1;
        else changes++;
    }

    std::cout << changes << std::endl;
    return 0;
}