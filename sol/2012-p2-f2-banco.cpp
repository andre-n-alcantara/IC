#include <iostream>
#include <queue>

using namespace std;

int main() {
    int C, N;
    cin >> C >> N;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila;
    int tempoAtual = 0;
    int atendidos = 0;
    int clientesEsperaMais20 = 0;

    for (int i = 0; i < N; i++) {
        int T, D;
        cin >> T >> D;

        while (T > tempoAtual) {
            if (!fila.empty() && fila.top().first <= tempoAtual) {
                atendidos++;
                fila.pop();
            } else {
                tempoAtual++;
            }
        }

        fila.push(make_pair(tempoAtual + D, i));
        if (fila.size() > C) {
            clientesEsperaMais20++;
            fila.pop();
        }
    }

    cout << clientesEsperaMais20 << endl;

    return 0;
}