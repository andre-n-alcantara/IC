
#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int price = 7;

    if (N > 10) {
        if (N > 30)
            price += (N > 100) ? 100 * 2 + (N - 100) * 5 : (30 - 10) * 1 + (N - 30) * 2;
        else
            price += (N - 10) * 1;
    }

    std::cout << price << std::endl;

    return 0;
}
