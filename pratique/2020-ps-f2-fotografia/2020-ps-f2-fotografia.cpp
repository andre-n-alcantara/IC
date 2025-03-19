#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int A, L, N;
    cin >> A >> L >> N;

    vector<pair<int, int>> frames(N);
    for (int i = 0; i < N; i++) {
        cin >> frames[i].first >> frames[i].second;
    }

    int bestFrame = -1;
    int minArea = INT_MAX;

    for (int i = 0; i < N; i++) {
        int area = max(A, frames[i].first) * max(L, frames[i].second) - A * L;
        if (area < minArea && (A <= frames[i].first && L <= frames[i].second || A <= frames[i].second && L <= frames[i].first)) {
            minArea = area;
            bestFrame = i + 1;
        }
    }

    cout << bestFrame << endl;

    return 0;
}