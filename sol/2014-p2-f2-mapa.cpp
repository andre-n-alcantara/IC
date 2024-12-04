#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<bool> visited;

int dfs(int node, int parent, int color) {
    visited[node] = true;
    int important = color && parent != -1;
    for (auto edge : graph[node]) {
        if (edge.first != parent) {
            important |= edge.second && dfs(edge.first, node, edge.second);
        }
    }
    return important;
}

int main() {
    int N;
    cin >> N;
    graph.resize(N + 1);
    visited.resize(N + 1, false);
    for (int i = 1; i < N; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }
    int E = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            fill(visited.begin(), visited.end(), false);
            if (dfs(i, -1, 0) && dfs(j, -1, 0)) {
                E++;
            }
        }
    }
    cout << E << endl;
    return 0;
}