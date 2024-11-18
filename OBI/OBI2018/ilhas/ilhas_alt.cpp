#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

const int MAX_N = 100005;

vector<pair<int, int>> adj[MAX_N];
int dist[MAX_N];

struct cmp {
    bool operator()(int u, int v) {
        if (dist[u] != dist[v]) return dist[u] < dist[v];
        return u < v;
    }
};

void dijkstra(int source) {
    fill(dist, dist + MAX_N, INF);
    dist[source] = 0;
    set<int, cmp> vert;
    vert.insert(source);
    while (!vert.empty()) {
        int u = *vert.begin(); vert.erase(vert.begin());
        for (int i = 0; i < (int) adj[u].size(); i++) {
            int v = adj[u][i].first;
            int c = adj[u][i].second;
            if (dist[u] + c < dist[v]) {
                vert.erase(v);
                dist[v] = dist[u] + c;
                vert.insert(v);
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    int s;
    scanf("%d", &s);
    dijkstra(s);

    int low = INF, high = -INF;
    for (int u = 1; u <= n; u++) {
        if (u == s) continue;
        low = min(low, dist[u]);
        high = max(high, dist[u]);
    }
    printf("%d\n", high-low);
}
