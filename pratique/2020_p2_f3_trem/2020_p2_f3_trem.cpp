#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_E = 1e4 + 5;
const int INF = 1e9;

vector<pair<int, int>> adj[MAX_E];
int dist[MAX_E];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int E, R;
    cin >> E >> R;

    for (int i = 1; i <= E; i++) {
        dist[i] = INF;
    }

    for (int i = 0; i < R; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        adj[A].emplace_back(B, C);
        adj[B].emplace_back(A, C);
    }

    int K;
    cin >> K;

    for (int i = 0; i < K; i++) {
        int X, T;
        cin >> X >> T;

        dijkstra(X);
        int ans = dist[X] * 2;

        if (ans <= T) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}