#include <ctime>
#include <iostream>
#include <algorithm>

int main() {
    double n[5];
    for (int i = 0; i < 5; i++) {
        std::cin >> n[i];
    }
    std::sort(n, n + 5);
    std::cout << std::fixed << std::setprecision(1) << n[1] + n[2] + n[3] << std::endl;
    
return 0;
}