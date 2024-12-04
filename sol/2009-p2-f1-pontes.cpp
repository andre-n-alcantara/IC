
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int to, cost;
};

vector<Edge> graph[1005];
int dist[1005];

int dijkstra(int start, int end) {
    fill(dist, dist + 1005, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (Edge e : graph[u]) {
            if (dist[u] + e.cost < dist[e.to]) {
                dist[e.to] = dist[u] + e.cost;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    return dist[end];
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int S, T, B;
        cin >> S >> T >> B;
        graph[S].push_back({T, B});
        graph[T].push_back({S, B});
    }
    cout << dijkstra(0, N + 1) << endl;
    return 0;
}
