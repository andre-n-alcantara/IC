#include <iostream>

int main() {
    int xm, ym, xr, yr;
    std::cin >> xm >> ym >> xr >> yr;
    std::cout << std::abs(xm - xr) + std::abs(ym - yr) << std::endl;
    return 0;
}