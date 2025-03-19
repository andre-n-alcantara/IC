#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Battery {
    double position, charge;
};

int main() {
    int N;
    double D;
    cin >> N >> D;

    vector<Battery> batteries(N);
    for (int i = 0; i < N; i++) {
        cin >> batteries[i].position >> batteries[i].charge;
    }

    sort(batteries.begin(), batteries.end(), [](const Battery& a, const Battery& b) {
        return a.position < b.position;
    });

    double time = 0.0;
    double remainingDistance = D;
    for (int i = 0; i < N; i++) {
        double distanceToNextBattery = (i == N - 1) ? remainingDistance : batteries[i + 1].position - batteries[i].position;
        double velocity = batteries[i].charge / distanceToNextBattery;
        time += distanceToNextBattery / velocity;
        remainingDistance -= distanceToNextBattery;
    }

    printf("%.3f\n", time);

    return 0;
}