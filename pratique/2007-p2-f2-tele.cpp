#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Ligacao {
    int tempo;
};

struct Vendedor {
    int id;
    int ligações;
    int tempoOcupado;
};

int main() {
    int N, L;
    cin >> N >> L;

    vector<Ligacao> ligações(L);
    for (int i = 0; i < L; i++) {
        cin >> ligações[i].tempo;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> filaVendedores;
    for (int i = 1; i <= N; i++) {
        filaVendedores.push({0, i});
    }

    vector<Vendedor> vendedores(N);
    for (int i = 0; i < L; i++) {
        pair<int, int> tempoVendedor = filaVendedores.top();
        filaVendedores.pop();

        int tempoLigacao = ligações[i].tempo;
        vendedores[tempoVendedor.second - 1].ligações++;
        vendedores[tempoVendedor.second - 1].tempoOcupado = tempoVendedor.first + tempoLigacao;

        filaVendedores.push({vendedores[tempoVendedor.second - 1].tempoOcupado, tempoVendedor.second});
    }

    for (int i = 0; i < N; i++) {
        cout << i + 1 << " " << vendedores[i].ligações << endl;
    }

    return 0;
}