#include <bits/stdc++.h>
using namespace std;

#define INF 1000000

vector<pair<int, int>> adj[105];
int dist[105];

void dijkstra(int start) {
    fill(dist, dist + 105, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if (d > dist[v])
            continue;
        for (auto e : adj[v]) {
            if (dist[v] + e.second < dist[e.first]) {
                dist[e.first] = dist[v] + e.second;
                pq.push({dist[e.first], e.first});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        adj[A].push_back({B, C});
        adj[B].push_back({A, C});
    }
    dijkstra(1);
    cout << dist[N] << endl;
    return 0;
}