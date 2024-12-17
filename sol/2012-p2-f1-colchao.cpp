#include <ctime>
#include <iostream>
using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int A, B, C, H, L;
    cin >> A >> B >> C;
    cin >> H >> L;

    if (max(A, max(B, C)) <= max(H, L) && min(A, min(B, C)) <= min(H, L)) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}