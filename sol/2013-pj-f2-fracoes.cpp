#include <ctime>
#include <iostream>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    std::clock_t startTime = std::clock();
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    int numerator = a * d + c * b;
    int denominator = b * d;

    int div = gcd(numerator, denominator);
    numerator /= div;
    denominator /= div;

    std::cout << numerator << " " << denominator << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}