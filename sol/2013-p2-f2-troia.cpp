#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> rank;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    parent.resize(N + 1);
    rank.resize(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        unionSets(x, y);
    }
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (parent[i] == i) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}