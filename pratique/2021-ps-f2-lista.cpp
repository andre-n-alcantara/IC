#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> lista(N);
    for (int i = 0; i < N; i++) {
        cin >> lista[i];
    }

    int operacoes = 0;
    int esq = 0, dir = N - 1;
    while (esq < dir) {
        if (lista[esq] != lista[dir]) {
            if (lista[esq] < lista[dir]) {
                lista[esq + 1] += lista[esq];
                esq++;
            } else {
                lista[dir - 1] += lista[dir];
                dir--;
            }
            operacoes++;
        } else {
            esq++;
            dir--;
        }
    }

    cout << operacoes << endl;
    return 0;
}