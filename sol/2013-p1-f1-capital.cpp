#include <ctime>
#include <iostream>
using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int A1, A2, A3, A4;
    cin >> A1 >> A2 >> A3 >> A4;
    int areas[4] = {A1, A2, A3, A4};
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            int otherAreas = A1 + A2 + A3 + A4 - areas[i] - areas[j];
            if (areas[i] + areas[j] == otherAreas) {
                cout << "S" << endl;
                
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
            }
        }
    }
    cout << "N" << endl;
    return 0;
}