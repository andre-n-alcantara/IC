#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N;
    cin >> N;

    vector<pair<int, int>> towers(N);
    for (int i = 0; i < N; i++) {
        cin >> towers[i].first >> towers[i].second;
    }

    int A;
    cin >> A;

    bool canCover = true;
    for (int i = 0; i < N; i++) {
        bool canReach = false;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                int dx = towers[i].first - towers[j].first;
                int dy = towers[i].second - towers[j].second;
                int dist = dx * dx + dy * dy;
                if (dist <= A * A) {
                    canReach = true;
                    break;
                }
            }
        }
        if (!canReach) {
            canCover = false;
            break;
        }
    }

    cout << (canCover ? "S" : "N") << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}