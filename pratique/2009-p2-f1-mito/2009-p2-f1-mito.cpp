#include <ctime>
#include <iostream>
#include <set>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N;
    cin >> N;

    set<pair<int, int>> raios;

    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;
        if (!raios.insert({X, Y}).second) {
            cout << 1 << endl;
            
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}