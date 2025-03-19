#include <ctime>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 105;

vector<int> graph[MAX_N];
int parent[MAX_N];
int depth[MAX_N];
int low[MAX_N];

void dfs(int node, int pai, int d) {
    parent[node] = pai;
    depth[node] = d;
    low[node] = d;

    for (int child : graph[node]) {
        if (child == pai) continue;
        if (depth[child] == 0) {
            dfs(child, node, d + 1);
            low[node] = min(low[node], low[child]);
        } else {
            low[node] = min(low[node], depth[child]);
        }
    }
}

int find_lca(int a, int b) {
    while (depth[a] > depth[b]) a = parent[a];
    while (depth[b] > depth[a]) b = parent[b];

    while (a != b) {
        a = parent[a];
        b = parent[b];
    }

    return a;
}

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int fi;
        cin >> fi;
        graph[i].push_back(fi);
    }

    int Q;
    cin >> Q;

    for (int i = 1; i <= N; i++) {
        if (graph[i].size() == 1) {
            dfs(i, 0, 1);
        }
    }

    for (int i = 0; i < Q; i++) {
        int A, B;
        cin >> A >> B;

        int lca = find_lca(A, B);
        int ans = max(depth[A], depth[B]) - 2 * depth[lca];
        cout << ans << endl;
    }

    
return 0;
}