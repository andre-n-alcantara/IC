#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, rank;

int find(int u) {
    if (parent[u] != u) parent[u] = find(parent[u]);
    return parent[u];
}

void unionSets(int u, int v) {
    int root1 = find(u), root2 = find(v);
    if (root1 != root2) {
        if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
        } else {
            parent[root1] = root2;
            if (rank[root1] == rank[root2]) rank[root2]++;
        }
    }
}

int main() {
    int N;
    cin >> N;
    parent.resize(N + 1);
    rank.resize(N + 1, 0);
    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        unionSets(u, v);
    }

    int count[N + 1];
    memset(count, 0, sizeof(count));
    for (int i = 1; i <= N; i++) count[find(i)]++;

    int best = N;
    for (int i = 1; i <= N; i++) {
        best = min(best, abs(N - 2 * count[i]));
    }

    cout << best << endl;
    
return 0;
}