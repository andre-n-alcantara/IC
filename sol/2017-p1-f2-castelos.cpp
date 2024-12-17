#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent, color, depth;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (depth[x] < depth[y]) {
            swap(x, y);
        }
        parent[y] = x;
        if (depth[x] == depth[y]) {
            depth[x]++;
        }
    }
}

int main() {
    std::clock_t startTime = std::clock();
    int N, M;
    cin >> N >> M;

    parent.resize(N + 1);
    color.resize(N + 1);
    depth.resize(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        color[i] = 0;
    }

    for (int i = 1; i < N; i++) {
        int U, V;
        cin >> U >> V;
        union_set(U, V);
    }

    for (int i = 0; i < M; i++) {
        int P, Q, C;
        cin >> P >> Q >> C;
        int rootP = find(P);
        int rootQ = find(Q);
        while (rootP != rootQ) {
            color[rootP] = C;
            rootP = find(parent[rootP]);
        }
        color[Q] = C;
    }

    for (int i = 1; i <= N; i++) {
        cout << color[i] << " ";
    }
    cout << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}