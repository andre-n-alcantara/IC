#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> arrows;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        arrows.push_back({x, y});
    }

    vector<int> penalties(N);
    penalties[0] = 0;

    for (int i = 1; i < N; i++) {
        int px = arrows[i].first - penalties[i-1];
        int py = arrows[i].second - penalties[i-1];
        int pen = 0;
        for (int j = 0; j < i; j++) {
            int dx = arrows[j].first - px;
            int dy = arrows[j].second - py;
            if (dx * dx + dy * dy <= px * px + py * py) {
                pen++;
            }
        }
        penalties[i] = pen;
    }

    for (int i = 0; i < N; i++) {
        cout << penalties[i] << endl;
    }

    return 0;
}