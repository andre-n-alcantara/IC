
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<string> graph[10001];
vector<bool> visited(10001, false);

void bfs(string start, string target, vector<string> &seq) {
    queue<pair<string, int>> q;
    q.push({start, 0});
    visited[seq.size() - 1] = true;

    while (!q.empty()) {
        string v = q.front().first;
        int d = q.front().second;
        q.pop();

        if (v == target) {
            cout << d << endl;
            return;
        }

        for (string w : graph[seq.size() - 1]) {
            if (!visited[seq.size() - 1]) {
                q.push({w, d + 1});
                visited[seq.size() - 1] = true;
            }
        }

        for (int i = 0; i < seq.size() - 1; i++) {
            if (seq[i] == v) {
                if (!visited[i]) {
                    q.push({seq[i + 1], d + 1});
                    visited[i] = true;
                }
                if (!visited[i + 1]) {
                    q.push({seq[i], d + 1});
                    visited[i + 1] = true;
                }
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<string> seq(N + 1);
    for (int i = 0; i < N; i++) {
        string X, Y;
        cin >> X >> Y;
        graph[i].push_back(Y);
    }

    for (int i = 0; i < N; i++) {
        cin >> seq[i];
    }

    sort(seq.begin(), seq.end());

    for (int i = 0; i < N; i++) {
        graph[i].push_back(seq[i + 1]);
        graph[i + 1].push_back(seq[i]);
    }

    string P, A;
    cin >> P >> A;

    bfs(P, A, seq);

    return 0;
}
