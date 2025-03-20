#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> height;
vector<bool> visited;

int dfs(int node) {
    if (visited[node]) return 0;
    visited[node] = true;
    int count = 0;
    for (int neighbor : graph[node]) {
        if (height[neighbor] < height[node]) {
            count += dfs(neighbor);
        }
    }
    return count + 1;
}

int main() {
    int S, T, P;
    cin >> S >> T >> P;
    graph.resize(S + 1);
    height.resize(S + 1);
    visited.resize(S + 1, false);
    for (int i = 1; i <= S; i++) {
        cin >> height[i];
    }
    for (int i = 0; i < T; i++) {
        int I, J;
        cin >> I >> J;
        graph[I].push_back(J);
        graph[J].push_back(I);
    }
    cout << dfs(P) - 1 << endl;
    return 0;
}