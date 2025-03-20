#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[50005];
int low[50005], disc[50005], timer;
int n, max_cycle, cycle_count;

void dfs(int u, int parent) {
    low[u] = disc[u] = timer++;
    int children = 0;
    for (int v : adj[u]) {
        if (v == parent) continue;
        if (disc[v] == 0) {
            children++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u])
                max_cycle = max(max_cycle, children + 1);
        } else
            low[u] = min(low[u], disc[v]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    timer = 1;
    max_cycle = 0;
    cycle_count = 0;
    for (int i = 1; i <= n; i++) {
        if (disc[i] == 0) {
            dfs(i, -1);
            if (max_cycle > 0) cycle_count++;
            max_cycle = 0;
        }
    }
    cout << max_cycle << "\n" << cycle_count << "\n";
    
return 0;
}