#include <iostream>
using namespace std;

int calc_pontuacao(int carta1, int carta2) {
    if (carta1 == carta2) return 2 * (carta1 + carta2);
    if (abs(carta1 - carta2) == 1) return 3 * (carta1 + carta2);
    return carta1 + carta2;
}

int main() {
    int lia_carta1, lia_carta2, carolina_carta1, carolina_carta2;
    cin >> lia_carta1 >> lia_carta2 >> carolina_carta1 >> carolina_carta2;

    int lia_pontuacao = calc_pontuacao(lia_carta1, lia_carta2);
    int carolina_pontuacao = calc_pontuacao(carolina_carta1, carolina_carta2);

    if (lia_pontuacao > carolina_pontuacao) cout << "Lia" << endl;
    else if (lia_pontuacao < carolina_pontuacao) cout << "Carolina" << endl;
    else cout << "empate" << endl;

    return 0;
}