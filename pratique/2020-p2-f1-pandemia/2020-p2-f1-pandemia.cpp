#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, M, I, R;
    cin >> N >> M >> I >> R;

    vector<set<int>> reunioes(M + 1);
    for (int i = 1; i <= M; i++) {
        int A;
        cin >> A;
        for (int j = 0; j < A; j++) {
            int P;
            cin >> P;
            reunioes[i].insert(P);
        }
    }

    set<int> infectados;
    infectados.insert(I);

    for (int i = R; i <= M; i++) {
        for (int amigo : reunioes[i]) {
            if (infectados.count(amigo)) {
                for (int outro : reunioes[i]) {
                    infectados.insert(outro);
                }
                break;
            }
        }
    }

    cout << infectados.size() << endl;

    return 0;
}