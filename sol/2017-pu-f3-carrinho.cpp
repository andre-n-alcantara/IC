
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    double D;
    cin >> N >> D;

    vector<pair<double, double>> batteries(N);
    for (int i = 0; i < N; i++) {
        cin >> batteries[i].first >> batteries[i].second;
    }

    double time = 0.0;
    double currPos = 0.0;
    double currBat = batteries[0].second;

    for (int i = 1; i < N; i++) {
        double nextPos = batteries[i].first;
        double nextBat = batteries[i].second;

        double vel = currBat / (nextPos - currPos);
        time += (nextPos - currPos) / vel;

        currPos = nextPos;
        currBat = nextBat;
    }

    time += D / currBat;

    printf("%.3f\n", time);

    return 0;
}
