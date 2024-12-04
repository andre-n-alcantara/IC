
#include <iostream>

int main() {
    int n1, d1, v1, n2, d2, v2;
    std::cin >> n1 >> d1 >> v1;
    std::cin >> n2 >> d2 >> v2;

    double t1 = static_cast<double>(d1) / (v1 * 1000 / 3600);
    double t2 = static_cast<double>(d2) / (v2 * 1000 / 3600);

    if (t1 < t2)
        std::cout << n1 << std::endl;
    else
        std::cout << n2 << std::endl;

    return 0;
}
