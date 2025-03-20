#include <ctime>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 50000;

vector<pair<int, int>> graph[MAX_N + 1];

int dfs(int node, int company, vector<bool>& visited) {
    visited[node] = true;
    int max_path = 1;

    for (auto edge : graph[node]) {
        int next_node = edge.first;
        int next_company = edge.second;

        if (!visited[next_node] && (company != next_company)) {
            max_path = max(max_path, 1 + dfs(next_node, next_company, visited));
        }
    }

    return max_path;
}

int main() {
    int N;
    cin >> N;

    for (int i = 1; i < N; i++) {
        int A, B, E;
        cin >> A >> B >> E;
        graph[A].push_back({B, E});
        graph[B].push_back({A, E});
    }

    int max_path = 0;
    for (int i = 1; i <= N; i++) {
        vector<bool> visited(N + 1, false);
        max_path = max(max_path, dfs(i, 0, visited));
        max_path = max(max_path, dfs(i, 1, visited));
    }

    cout << max_path << endl;

    
return 0;
}