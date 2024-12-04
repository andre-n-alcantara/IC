
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSets(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) {
        parent[px] = py;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++) {
        int I, J;
        cin >> I >> J;
        unionSets(I, J);
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
