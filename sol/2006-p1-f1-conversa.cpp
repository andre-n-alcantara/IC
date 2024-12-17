#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, M, X, Y, K;
    cin >> N >> M >> X >> Y >> K;

    vector<int> dirs(K);
    for (int i = 0; i < K; i++) {
        cin >> dirs[i];
    }

    int x = 0, y = 0;
    int minutes = 0;

    for (int i = 0; i < K; i++) {
        if (abs(x - X) <= 1 && abs(y - Y) <= 1) {
            minutes++;
        }

        if (dirs[i] == 1) {
            y++;
        } else if (dirs[i] == 2) {
            y--;
        } else if (dirs[i] == 3) {
            x++;
        } else {
            x--;
        }
    }

    if (abs(x - X) <= 1 && abs(y - Y) <= 1) {
        minutes++;
    }

    cout << minutes << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}