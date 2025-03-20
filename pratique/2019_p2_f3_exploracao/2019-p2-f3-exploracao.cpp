#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, P, Q;
    cin >> N >> P >> Q;

    vector<pair<int, int>> titans(N);
    for (int i = 0; i < N; i++) {
        cin >> titans[i].first >> titans[i].second;
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int dx = titans[j].first - titans[i].first;
            int dy = titans[j].second - titans[i].second;
            if (dx == 0) continue;
            if (dy * Q >= dx * P) {
                count++;
            }
        }
    }

    cout << count << endl;

    
return 0;
}