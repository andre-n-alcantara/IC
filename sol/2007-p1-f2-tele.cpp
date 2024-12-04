
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Ligacao {
    int tempo;
    int vendedor;
};

int main() {
    int N, L;
    cin >> N >> L;

    priority_queue<Ligacao, vector<Ligacao>, function<bool(Ligacao, Ligacao)>> pq(
        [](Ligacao a, Ligacao b) { return a.tempo > b.tempo; });

    vector<int> ligações(N, 0);

    for (int i = 0; i < L; i++) {
        int T;
        cin >> T;
        pq.push({T, i % N + 1});
    }

    while (!pq.empty()) {
        Ligacao ligacao = pq.top();
        pq.pop();
        ligações[ligacao.vendedor - 1]++;
        pq.push({ligacao.tempo - 1, ligacao.vendedor});
        if (ligacao.tempo - 1 > 0) pq.push({ligacao.tempo - 1, ligacao.vendedor});
    }

    for (int i = 0; i < N; i++) {
        cout << i + 1 << " " << ligações[i] << endl;
    }

    return 0;
}
