#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Edge {
    int to, cost;
};

vector<Edge> graph[1001];
int dist[1001];

void dijkstra(int start) {
    fill(dist, dist + 1001, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (Edge e : graph[u]) {
            int v = e.to, c = e.cost;
            if (dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v, p;
        cin >> u >> v >> p;
        graph[u].push_back({v, p});
        graph[v].push_back({u, p});
    }
    int S;
    cin >> S;
    dijkstra(S);
    int minPing = INF, maxPing = 0;
    for (int i = 1; i <= N; i++) {
        if (i != S) {
            minPing = min(minPing, dist[i]);
            maxPing = max(maxPing, dist[i]);
        }
    }
    cout << maxPing - minPing << endl;
    return 0;
}