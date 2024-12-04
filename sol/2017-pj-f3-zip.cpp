
#include <iostream>
using namespace std;

int calcula_pontuacao(int carta1, int carta2) {
    if (carta1 == carta2) {
        return 2 * (carta1 + carta2);
    } else if (abs(carta1 - carta2) == 1) {
        return 3 * (carta1 + carta2);
    } else {
        return carta1 + carta2;
    }
}

int main() {
    int lia_carta1, lia_carta2, carolina_carta1, carolina_carta2;
    cin >> lia_carta1 >> lia_carta2 >> carolina_carta1 >> carolina_carta2;

    int lia_pontuacao = calcula_pontuacao(lia_carta1, lia_carta2);
    int carolina_pontuacao = calcula_pontuacao(carolina_carta1, carolina_carta2);

    if (lia_pontuacao > carolina_pontuacao) {
        cout << "Lia" << endl;
    } else if (carolina_pontuacao > lia_pontuacao) {
        cout << "Carolina" << endl;
    } else {
        cout << "empate" << endl;
    }

    return 0;
}
