#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void union_set(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    if (root_x != root_y) {
        parent[root_x] = root_y;
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < K; i++) {
        char op;
        cin >> op;
        if (op == 'F') {
            int x, y;
            cin >> x >> y;
            union_set(x, y);
        } else {
            int x, y;
            cin >> x >> y;
            if (find(x) == find(y)) {
                cout << "S" << endl;
            } else {
                cout << "N" << endl;
            }
        }
    }

    
return 0;
}