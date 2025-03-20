#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> heights;
vector<bool> visited;

int dfs(int node) {
    visited[node] = true;
    int count = 0;
    for (auto &edge : graph[node]) {
        if (!visited[edge.first] && heights[node] > heights[edge.first]) {
            count += dfs(edge.first);
        }
    }
    return count;
}

int main() {
    int S, T, P;
    cin >> S >> T >> P;
    heights.resize(S + 1);
    graph.resize(S + 1);
    visited.resize(S + 1, false);

    for (int i = 1; i <= S; i++) {
        cin >> heights[i];
    }

    for (int i = 0; i < T; i++) {
        int I, J;
        cin >> I >> J;
        graph[I].push_back({J, i});
        graph[J].push_back({I, i});
    }

    cout << dfs(P) << endl;

    return 0;
}