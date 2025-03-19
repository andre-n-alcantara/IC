#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
const int MAX_E = 1e4;
const int MAX_R = 2 * MAX_E;

vector<pair<int, int>> graph[MAX_E + 1];
int dist[MAX_E + 1];

void bfs(int start, int limit) {
    fill(dist, dist + MAX_E + 1, INF);
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, w] : graph[u]) {
            if (w <= limit && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    }
}

int main() {
    int E, R;
    cin >> E >> R;
    for (int i = 0; i < R; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int X, T;
        cin >> X >> T;
        bfs(X, T);
        int ans = dist[X] == INF ? -1 : dist[X] * 2;
        cout << ans << endl;
    }
    return 0;
}