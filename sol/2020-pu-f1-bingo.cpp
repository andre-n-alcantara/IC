#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N, K, U;
    cin >> N >> K >> U;

    vector<vector<int>> cartelas(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            int num;
            cin >> num;
            cartelas[i].push_back(num);
        }
    }

    vector<int> sorteio(U);
    for (int i = 0; i < U; i++) {
        cin >> sorteio[i];
    }

    vector<int> vencedoras;
    for (int i = 0; i < N; i++) {
        set<int> numeros(cartelas[i].begin(), cartelas[i].end());
        int k = 0;
        for (int j = 0; j < U; j++) {
            if (numeros.find(sorteio[j]) != numeros.end()) {
                k++;
                if (k == K) {
                    vencedoras.push_back(i + 1);
                    break;
                }
            }
        }
    }

    sort(vencedoras.begin(), vencedoras.end());
    for (int i = 0; i < vencedoras.size(); i++) {
        cout << vencedoras[i];
        if (i < vencedoras.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}