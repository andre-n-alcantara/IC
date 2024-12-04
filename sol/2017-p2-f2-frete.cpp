
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;
const int INF = 0x3f3f3f3f;

vector<pair<int, int>> adj[MAXN];
int dist[MAXN];

void dijkstra(int start) {
    fill(dist, dist + MAXN, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int u = pq.top().second;
        int d_u = pq.top().first;
        pq.pop();
        if (d_u != dist[u]) continue;
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
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        adj[A].push_back({B, C});
        adj[B].push_back({A, C});
    }
    dijkstra(1);
    printf("%d\n", dist[N]);
    return 0;
}
