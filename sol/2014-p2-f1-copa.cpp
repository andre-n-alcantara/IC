#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, cost;
    bool isRoad;
};

vector<Edge> edges;
vector<int> parent;

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void unionEdges(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) parent[u] = v;
}

int kruskal() {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.cost < b.cost;
    });

    int cost = 0;
    for (Edge e : edges) {
        if (find(e.u) != find(e.v)) {
            cost += e.cost;
            unionEdges(e.u, e.v);
        }
    }

    return cost;
}

int main() {
    std::clock_t startTime = std::clock();
    int N, F, R;
    cin >> N >> F >> R;

    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int i = 0; i < F; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        edges.push_back({u, v, cost, false});
    }

    for (int i = 0; i < R; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        edges.push_back({u, v, cost, true});
    }

    int minCost = kruskal();
    int minRoads = 0;
    for (Edge e : edges) {
        if (e.isRoad && find(e.u) != find(e.v)) {
            minRoads++;
        }
    }

    int finalCost = minCost;
    for (int i = 0; i < edges.size(); i++) {
        if (edges[i].isRoad) {
            swap(edges[i], edges[0]);
            int newCost = kruskal();
            if (newCost < finalCost) {
                finalCost = newCost;
                minRoads--;
            }
            swap(edges[i], edges[0]);
        }
    }

    cout << finalCost << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}