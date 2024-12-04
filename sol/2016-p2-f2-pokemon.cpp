#include <iostream>

int main() {
    int N, X, Y, Z;
    std::cin >> N >> X >> Y >> Z;

    int count = 0;
    if (N >= X) {
        N -= X;
        count++;
    }
    if (N >= Y) {
        N -= Y;
        count++;
    }
    if (N >= Z) {
        N -= Z;
        count++;
    }

    std::cout << count << std::endl;

    return 0;
}