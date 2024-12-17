#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Var {
    string name;
    int value;
};

vector<Var> vars;
vector<vector<string>> lines;
vector<int> cols;
vector<int> lineSums;
vector<int> colSums;

void solve() {
    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines[i].size(); j++) {
            string varName = lines[i][j];
            int sum = lineSums[i];
            for (int k = 0; k < lines[i].size(); k++) {
                if (k != j) {
                    sum -= vars[lines[i][k]].value;
                }
            }
            vars[varName].value = sum;
        }
    }

    for (int j = 0; j < cols.size(); j++) {
        for (int i = 0; i < lines.size(); i++) {
            string varName = lines[i][j];
            int sum = colSums[j];
            for (int k = 0; k < lines.size(); k++) {
                if (k != i) {
                    sum -= vars[lines[k][j]].value;
                }
            }
            vars[varName].value = sum;
        }
    }
}

int main() {
    std::clock_t startTime = std::clock();
    int L, C;
    cin >> L >> C;

    lines.resize(L);
    cols.resize(C);
    lineSums.resize(L);
    colSums.resize(C);

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            string varName;
            cin >> varName;
            lines[i].push_back(varName);
            vars[varName] = {varName, 0};
        }
        cin >> lineSums[i];
    }

    for (int j = 0; j < C; j++) {
        cin >> colSums[j];
    }

    solve();

    vector<Var> sortedVars(vars.begin(), vars.end());
    sort(sortedVars.begin(), sortedVars.end(), [](Var a, Var b) {
        return a.name < b.name;
    });

    for (auto v : sortedVars) {
        cout << v.name << " " << v.value << endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}