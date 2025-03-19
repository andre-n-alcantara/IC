#include <ctime>
#include <iostream>
using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a == b && c == d) || (a == c && b == d) || (a == d && b == c))
        cout << "F" << endl;
    else
        cout << "V" << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}