#include <iostream>

int main() {
    int maior = 0, num;
    while (true) {
        std::cin >> num;
        if (num == 0) break;
        if (num > maior) maior = num;
    }
    std::cout << maior << std::endl;
    return 0;
}