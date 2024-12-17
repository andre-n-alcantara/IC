#include <ctime>
#include <iostream>

int main() {
    std::clock_t startTime = std::clock();
    int j, p, v, e, d;
    std::cin >> j >> p >> v >> e >> d;

    if (j == -1) {
        j = v + e + d;
    }
    if (p == -1) {
        p = 3 * v + e;
    }
    if (v == -1) {
        v = (p - e) / 3;
    }
    if (e == -1) {
        e = p - 3 * v;
    }
    if (d == -1) {
        d = j - v - e;
    }

    std::cout << j << " " << p << " " << v << " " << e << " " << d << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}