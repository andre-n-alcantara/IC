#include <iostream>

int main() {
    int C;
    std::cin >> C;
    char highway[C];
    std::cin >> highway;

    int panels = 0;
    for (int i = 0; i < C; i++) {
        if (highway[i] == 'P') panels += 2;
        else if (highway[i] == 'C') panels += 2;
        else if (highway[i] == 'A') panels += 1;
    }

    std::cout << panels << std::endl;

    return 0;
}