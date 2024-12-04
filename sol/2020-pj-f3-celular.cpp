
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
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

    return 0;
}
