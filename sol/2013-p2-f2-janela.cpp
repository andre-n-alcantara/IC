
#include <iostream>

int main() {
    int F1, F2, F3;
    std::cin >> F1 >> F2 >> F3;

    int area = 0;
    if (F1 < F2) area += F2 - F1;
    if (F2 < F3) area += F3 - F2;

    std::cout << area * 100 << std::endl;

    return 0;
}
