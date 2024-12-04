#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> graphC, graphQ;
vector<int> diameterC, diameterQ;

void bfs(int start, vector<vector<int>>& graph, vector<int>& diameter) {
    queue<int> q;
    vector<bool> visited(graph.size(), false);
    q.push(start);
    visited[start] = true;
    int maxDepth = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                maxDepth = max(maxDepth, distance(visited.begin(), find(visited.begin(), visited.end(), true)) - 1);
            }
        }
    }
    diameter[start] = maxDepth;
}

int main() {
    cin >> n >> m;
    graphC.resize(n + 1);
    graphQ.resize(m + 1);
    diameterC.resize(n + 1, 0);
    diameterQ.resize(m + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graphC[a].push_back(b);
        graphC[b].push_back(a);
    }
    for (int i = 0; i < m - 1; i++) {
        int x, y;
        cin >> x >> y;
        graphQ[x].push_back(y);
        graphQ[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        bfs(i, graphC, diameterC);
    }
    for (int i = 1; i <= m; i++) {
        bfs(i, graphQ, diameterQ);
    }

    int minDiameter = INT_MAX;
    int cNode, qNode;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int newDiameter = max(max(diameterC[i], diameterQ[j]), max(diameterC[i], diameterQ[j]) + 1);
            if (newDiameter < minDiameter) {
                minDiameter = newDiameter;
                cNode = i;
                qNode = j;
            }
        }
    }

    cout << cNode << " " << qNode << endl;

    return 0;
}