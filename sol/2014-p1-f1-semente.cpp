
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int F, R;
    cin >> F >> R;
    vector<int> positions(R);
    for (int i = 0; i < R; i++) {
        cin >> positions[i];
    }
    sort(positions.begin(), positions.end());
    int max_day = 0;
    for (int i = 0; i < R; i++) {
        int day = max(positions[i] - 1, F - positions[i]);
        if (i > 0) {
            day = min(day, positions[i] - positions[i - 1]);
        }
        if (i < R - 1) {
            day = min(day, positions[i + 1] - positions[i]);
        }
        max_day = max(max_day, day);
    }
    cout << max_day << endl;
    return 0;
}
