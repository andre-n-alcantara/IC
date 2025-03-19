#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N, K, U;
    cin >> N >> K >> U;

    vector<vector<int>> cartelas(N, vector<int>(K));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cin >> cartelas[i][j];
        }
    }

    vector<int> sorteio(U);
    for (int i = 0; i < U; i++) {
        cin >> sorteio[i];
    }

    vector<int> marcacoes(N, 0);
    set<int> numerosSorteados;
    vector<int> vencedoras;

    for (int i = 0; i < U; i++) {
        numerosSorteados.insert(sorteio[i]);
        for (int j = 0; j < N; j++) {
            if (numerosSorteados.count(cartelas[j][0]) == K) {
                marcacoes[j] = i + 1;
                vencedoras.push_back(j + 1);
            }
        }
        if (!vencedoras.empty()) break;
    }

    sort(vencedoras.begin(), vencedoras.end());
    for (int i = 0; i < vencedoras.size(); i++) {
        cout << vencedoras[i] << " ";
    }
    cout << endl;

    return 0;
}