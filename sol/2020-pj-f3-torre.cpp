#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> dados(N, vector<int>(6));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> dados[i][j];
        }
    }

    int max_soma = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) {
            int soma = 0;
            int face_atual = dados[i][j];
            int idx_atual = i;

            while (idx_atual < N) {
                soma += face_atual;
                for (int k = 0; k < 6; k++) {
                    if (dados[idx_atual][k] == face_atual) {
                        face_atual = dados[idx_atual][(k + 3) % 6];
                        break;
                    }
                }
                idx_atual++;
            }

            max_soma = max(max_soma, soma);
        }
    }

    cout << max_soma << endl;

    return 0;
}