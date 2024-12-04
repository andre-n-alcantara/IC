
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, M, P;
    cin >> N >> M >> P;
    vector<vector<bool>> lake(N + 1, vector<bool>(M + 1, false));
    for (int i = 0; i < P; i++) {
        int c, l;
        cin >> c >> l;
        lake[c][l] = true;
    }
    int sC, sL, rC, rL;
    cin >> sC >> sL >> rC >> rL;
    lake[sC][sL] = lake[rC][rL] = true;

    queue<pair<int, int>> q;
    q.push({sC, sL});
    bool found = false;
    while (!q.empty() && !found) {
        int c, l;
        tie(c, l) = q.front();
        q.pop();
        if (c == rC && l == rL) found = true;
        for (int dc = -3; dc <= 3; dc++) {
            if (dc == 0) continue;
            int nc = c + dc;
            if (nc >= 1 && nc <= N && lake[nc][l]) q.push({nc, l});
        }
        for (int dl = -3; dl <= 3; dl++) {
            if (dl == 0) continue;
            int nl = l + dl;
            if (nl >= 1 && nl <= M && lake[c][nl]) q.push({c, nl});
        }
    }

    cout << (found ? "S" : "N") << endl;

    return 0;
}
