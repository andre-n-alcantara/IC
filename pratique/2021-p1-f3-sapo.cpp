#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;

vector<bool> visited[MAX_N + 1][MAX_M + 1];
vector<pair<int, int>> stones[MAX_N + 1][MAX_M + 1];

int N, M, P;
int S_C, S_L, R_C, R_L;

bool is_valid(int c, int l) {
    return (1 <= c && c <= N) && (1 <= l && l <= M) && !visited[c][l];
}

bool bfs() {
    queue<pair<int, int>> q;
    q.push({S_C, S_L});
    visited[S_C][S_L] = true;

    while (!q.empty()) {
        int c = q.front().first;
        int l = q.front().second;
        q.pop();

        if (c == R_C && l == R_L) return true;

        for (int dc = -3; dc <= 3; dc++) {
            if (dc == 0) continue;
            int nc = c + dc;
            if (is_valid(nc, l) && stones[nc][l].size() > 0) {
                q.push({nc, l});
                visited[nc][l] = true;
            }
        }

        for (int dl = -3; dl <= 3; dl++) {
            if (dl == 0) continue;
            int nl = l + dl;
            if (is_valid(c, nl) && stones[c][nl].size() > 0) {
                q.push({c, nl});
                visited[c][nl] = true;
            }
        }
    }

    return false;
}

int main() {
    cin >> N >> M;
    cin >> P;

    for (int i = 0; i < P; i++) {
        int c, l;
        cin >> c >> l;
        stones[c][l].push_back({c, l});
    }

    cin >> S_C >> S_L;
    cin >> R_C >> R_L;

    if (bfs()) cout << "S" << endl;
    else cout << "N" << endl;

    return 0;
}