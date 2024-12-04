#include <iostream>

int main() {
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

    return 0;
}