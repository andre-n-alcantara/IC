#include <ctime>
#include <iostream>
#include <cmath>

int main() {
    std::clock_t startTime = std::clock();
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

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}