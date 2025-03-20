#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int verificaMagico(vector<vector<int>> &matriz, int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += matriz[0][i];
    }

    for (int i = 0; i < n; i++) {
        int linhaSoma = 0;
        int colunaSoma = 0;
        int diag1Soma = 0;
        int diag2Soma = 0;

        for (int j = 0; j < n; j++) {
            linhaSoma += matriz[i][j];
            colunaSoma += matriz[j][i];
        }

        if (linhaSoma != soma || colunaSoma != soma) {
            return -1;
        }

        diag1Soma += matriz[i][i];
        diag2Soma += matriz[i][n - i - 1];
    }

    if (diag1Soma != soma || diag2Soma != soma) {
        return -1;
    }

    return soma;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matriz(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    cout << verificaMagico(matriz, n) << endl;

    
return 0;
}