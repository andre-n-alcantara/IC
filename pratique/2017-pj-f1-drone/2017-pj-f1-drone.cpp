#include <ctime>
#include <iostream>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int A, B, C, H, L;
    cin >> A >> B >> C >> H >> L;
    if ((A <= H && B <= L) || (A <= L && B <= H) || (B <= H && A <= L) || (B <= L && A <= H) || (C <= H && A <= L) || (C <= L && A <= H) || (C <= H && B <= L) || (C <= L && B <= H))
        cout << "S" << endl;
    else
        cout << "N" << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}