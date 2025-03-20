#include <iostream>

int main() {
    int cibele, camila, celeste;
    std::cin >> cibele >> celeste >> camila;
    if (cibele > camila) std::swap(cibele, camila);
    if (camila > celeste) std::swap(camila, celeste);
    std::cout << camila << std::endl;
    return 0;
}