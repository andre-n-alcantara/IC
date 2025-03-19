#include <ctime>
#include <iostream>
using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int A1, B1, A2, B2, A, B;
    cin >> A1 >> B1 >> A2 >> B2 >> A >> B;

    if ((A1 == A && (B1 + B2 == B)) || (B1 == A && (A1 + A2 == B)) ||
        (A2 == A && (B1 + B2 == B)) || (B2 == A && (A1 + A2 == B)) ||
        (A1 == B && (B1 + A2 == A)) || (B1 == B && (A1 + A2 == A)) ||
        (A2 == B && (B1 + A2 == A)) || (B2 == B && (A1 + A2 == A)))
        cout << "S" << endl;
    else
        cout << "N" << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}