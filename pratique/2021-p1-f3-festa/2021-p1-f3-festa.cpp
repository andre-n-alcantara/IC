#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<bool> lista(N + 1, true);

    for (int i = 0; i < M; i++) {
        int Ti;
        cin >> Ti;
        for (int j = Ti; j <= N; j += Ti) {
            lista[j] = false;
        }
    }

    int cont = 0;
    for (int i = 1; i <= N; i++) {
        if (lista[i]) {
            cout << i << endl;
            cont++;
            if (cont == 10000) break;
        }
    }

    
return 0;
}