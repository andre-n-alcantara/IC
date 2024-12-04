
#include <iostream>
#include <vector>

using namespace std;

vector<int> mem;

void inverte(int x, int y) {
    while (x < y) {
        swap(mem[x-1], mem[y-1]);
        x++;
        y--;
    }
}

void soma(int x, int y) {
    int total = 0;
    for (int i = x; i <= y; i++) {
        total += mem[i-1];
    }
    cout << total << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    mem.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        mem[i] = i;
    }
    for (int i = 0; i < m; i++) {
        char op;
        int x, y;
        cin >> op >> x >> y;
        if (op == 'I') {
            inverte(x, y);
        } else {
            soma(x, y);
        }
    }
    return 0;
}
