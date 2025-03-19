#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, c;
};

bool comp(const Edge& a, const Edge& b) {
    return a.c < b.c;
}

int find(int x, int parent[]) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x], parent);
}

void union_sets(int x, int y, int parent[], int rank[]) {
    int root_x = find(x, parent);
    int root_y = find(y, parent);

    if (rank[root_x] < rank[root_y]) {
        parent[root_x] = root_y;
    } else if (rank[root_x] > rank[root_y]) {
        parent[root_y] = root_x;
    } else {
        parent[root_y] = root_x;
        rank[root_x]++;
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].c;
    }

    sort(edges.begin(), edges.end(), comp);

    int parent[N + 1], rank[N + 1];
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int total_cost = 0;
    for (int i = 0; i < M; i++) {
        int u = edges[i].u, v = edges[i].v;
        if (find(u, parent) != find(v, parent)) {
            total_cost += edges[i].c;
            union_sets(u, v, parent, rank);
        }
    }

    cout << total_cost << endl;

    
return 0;
}