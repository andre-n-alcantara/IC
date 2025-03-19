#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<vector<int>> chairs;

void print_solution(vector<pair<char, pair<int, int>>> solution) {
    cout << solution.size() << endl;
    for (auto& move : solution) {
        cout << move.first << " " << move.second.first << " " << move.second.second << endl;
    }
}

int main() {
    std::clock_t startTime = std::clock();
    cin >> L >> C;
    chairs.resize(L, vector<int>(C));
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> chairs[i][j];
        }
    }

    vector<pair<char, pair<int, int>>> solution;

    // Resolve as linhas
    for (int i = 0; i < L; ++i) {
        if (!is_sorted(chairs[i].begin(), chairs[i].end())) {
            sort(chairs[i].begin(), chairs[i].end());
            solution.emplace_back('L', i + 1, i + 2);
        }
    }

    // Resolve as colunas
    for (int j = 0; j < C; ++j) {
        vector<int> col(L);
        for (int i = 0; i < L; ++i) {
            col[i] = chairs[i][j];
        }
        if (!is_sorted(col.begin(), col.end())) {
            sort(col.begin(), col.end());
            for (int i = 0; i < L; ++i) {
                chairs[i][j] = col[i];
            }
            solution.emplace_back('C', j + 1, j + 2);
        }
    }

    print_solution(solution);

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}