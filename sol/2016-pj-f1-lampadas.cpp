#include <ctime>
#include <iostream>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int n;
    cin >> n;
    bool lampA = false, lampB = false;
    for(int i = 0; i < n; i++) {
        int press;
        cin >> press;
        if(press == 1) {
            lampA = !lampA;
        } else {
            lampA = !lampA;
            lampB = !lampB;
        }
    }
    cout << (lampA ? 1 : 0) << endl;
    cout << (lampB ? 1 : 0) << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}