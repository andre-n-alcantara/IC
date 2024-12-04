#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> tape(N);
    for (int i = 0; i < N; i++) {
        cin >> tape[i];
    }

    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (tape[i] == 0) {
            q.push(i);
            tape[i] = 0;
        } else {
            tape[i] = -1;
        }
    }

    int dist = 1;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int x = q.front();
            q.pop();
            if (x - 1 >= 0 && tape[x - 1] == -1) {
                tape[x - 1] = dist;
                q.push(x - 1);
            }
            if (x + 1 < N && tape[x + 1] == -1) {
                tape[x + 1] = dist;
                q.push(x + 1);
            }
        }
        dist = min(dist + 1, 9);
    }

    for (int i = 0; i < N; i++) {
        cout << tape[i] << " ";
    }
    cout << endl;

    return 0;
}