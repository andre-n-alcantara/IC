#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[100005];
int vis[100005], sz[100005];

void dfs(int node, int parent) {
    vis[node] = 1;
    sz[node] = 1;
    for (int child : graph[node]) {
        if (child != parent) {
            dfs(child, node);
            sz[node] += sz[child];
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, -1);
    int ans = n;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, abs(sz[i] - (n - sz[i])));
    }
    cout << ans << endl;
    return 0;
}