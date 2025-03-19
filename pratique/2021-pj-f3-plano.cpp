#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> plano(M);
    for (int i = 0; i < M; i++) {
        cin >> plano[i];
    }

    int vagas_ocupadas = 0;
    int clientes_atendidos = 0;

    for (int i = 0; i < M; i++) {
        if (vagas_ocupadas < plano[i]) {
            vagas_ocupadas = plano[i];
            clientes_atendidos++;
        }
    }

    cout << clientes_atendidos << endl;

    return 0;
}