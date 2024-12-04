
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> M(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> M[i][j];
        }
    }

    int maxWeight = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int weight = 0;
            for (int k = 0; k < N; k++) {
                if (k != j) weight += M[i][k];
            }
            for (int k = 0; k < N; k++) {
                if (k != i) weight += M[k][j];
            }
            weight -= M[i][j];
            maxWeight = max(maxWeight, weight);
        }
    }

    cout << maxWeight << endl;

    return 0;
}
