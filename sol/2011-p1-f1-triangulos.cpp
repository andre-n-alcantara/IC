#include <iostream>
#include <cmath>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    if (A + B <= C || A + C <= B || B + C <= A) {
        std::cout << "n" << std::endl;
    } else {
        int max = std::max({A, B, C});
        int a = (max == A) ? A : ((max == B) ? B : C);
        int b = (max == A) ? B : ((max == B) ? A : B);
        int c = (max == A) ? C : ((max == B) ? C : A);

        if (a*a == b*b + c*c) {
            std::cout << "r" << std::endl;
        } else if (a*a > b*b + c*c) {
            std::cout << "o" << std::endl;
        } else {
            std::cout << "a" << std::endl;
        }
    }

    return 0;
}