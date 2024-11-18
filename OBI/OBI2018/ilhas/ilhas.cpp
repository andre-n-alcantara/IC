#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;

const int INF = 1e9;

struct Edge {
    int v, c;
};

int main() {
    int n, m; scanf("%d %d", &n, &m);
    vector<vector<Edge>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v, c; scanf("%d %d %d", &u, &v, &c);
        u--, v--;
        adj[u].push_back(Edge{v, c});
        adj[v].push_back(Edge{u, c});
    }
    int s; scanf("%d", &s); s--;

    vector<int> dist(n, INF);
    auto cmp = [&dist](int u, int v) {
        if (dist[u] != dist[v]) return dist[u] < dist[v];
        return u < v;
    };
    set<int, function<bool(int, int)>> vert(cmp);

    dist[s] = 0;
    vert.insert(s);
    while (!vert.empty()) {
        int u = *vert.begin();
        vert.erase(vert.begin());

        for (Edge& e : adj[u]) {
            if (dist[u] + e.c < dist[e.v]) {
                vert.erase(e.v);
                dist[e.v] = dist[u] + e.c;
                vert.insert(e.v);
            }
        }
    }

    int min_dist = INF, max_dist = -INF;
    for (int i = 0; i < n; i++) {
        if (i != s) {
            min_dist = min(min_dist, dist[i]);
            max_dist = max(max_dist, dist[i]);
        }
    }

    printf("%d\n", max_dist - min_dist);
}
