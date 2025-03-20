#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> graph[1001];
set<int> infected;

int main() {
    int N, C;
    cin >> N >> C;

    for (int i = 0; i < C; i++) {
        int P, I;
        cin >> P >> I;
        for (int j = 0; j < I; j++) {
            int Xi;
            cin >> Xi;
            graph[P].push_back(Xi);
            infected.insert(Xi);
        }
    }

    set<int> zeroPatients;
    for (int i = 1; i <= N; i++) {
        if (infected.find(i) == infected.end()) {
            zeroPatients.insert(i);
        }
    }

    for (int patient : zeroPatients) {
        cout << patient << endl;
    }

    return 0;
}