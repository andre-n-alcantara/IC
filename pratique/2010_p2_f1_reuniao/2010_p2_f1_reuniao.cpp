#include <ctime>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

vector<vector<pii>> graph;
vector<int> dist;

int dijkstra(int start, int n) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto &edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    int max_dist = 0;
    for (int i = 0; i < n; i++) {
        max_dist = max(max_dist, dist[i]);
    }

    return max_dist;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    graph.assign(n, vector<pii>());
    dist.assign(n, INT_MAX);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dijkstra(i, n));
    }

    printf("%d\n", ans);

    
return 0;
}