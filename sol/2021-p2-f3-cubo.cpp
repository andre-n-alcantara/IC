
#include <iostream>
#include <cmath>

int main() {
    int A, B;
    std::cin >> A >> B;
    int count = 0;
    for (int i = A; i <= B; i++) {
        double cubeRoot = cbrt(i);
        double sqrtRoot = sqrt(i);
        if (cubeRoot == (int)cubeRoot && sqrtRoot == (int)sqrtRoot) {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
