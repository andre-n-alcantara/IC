#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

const int MAX_L = 100, MAX_C = 100;

vector<string> rows[MAX_L];
vector<string> cols[MAX_C];
vector<int> row_sums[MAX_L];
vector<int> col_sums[MAX_C];
map<string, int> vars;

void solve() {
    int L, C;
    cin >> L >> C;

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            string var;
            cin >> var;
            rows[i].push_back(var);
            cols[j].push_back(var);
        }
        int sum;
        cin >> sum;
        row_sums[i] = sum;
    }

    for (int i = 0; i < C; i++) {
        int sum;
        cin >> sum;
        col_sums[i] = sum;
    }

    queue<string> q;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            string var = rows[i][j];
            if (count(rows[i].begin(), rows[i].end(), var) == 1 ||
                count(cols[j].begin(), cols[j].end(), var) == 1) {
                q.push(var);
            }
        }
    }

    while (!q.empty()) {
        string var = q.front();
        q.pop();
        int sum = 0;
        for (int i = 0; i < L; i++) {
            if (find(rows[i].begin(), rows[i].end(), var) != rows[i].end()) {
                sum += row_sums[i];
                rows[i].erase(find(rows[i].begin(), rows[i].end(), var));
            }
        }
        for (int i = 0; i < C; i++) {
            if (find(cols[i].begin(), cols[i].end(), var) != cols[i].end()) {
                sum -= col_sums[i];
                cols[i].erase(find(cols[i].begin(), cols[i].end(), var));
            }
        }
        vars[var] = sum;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < C; j++) {
                string v = rows[i][j];
                if (count(rows[i].begin(), rows[i].end(), v) == 1 ||
                    count(cols[j].begin(), cols[j].end(), v) == 1) {
                    q.push(v);
                }
            }
        }
    }

    for (auto it = vars.begin(); it != vars.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}

int main() {
    solve();
    return 0;
}