#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int valorSimbolico(int carta) {
    switch (carta) {
        case 1:  return 11; // As
        case 2:  return 12; // 2
        case 3:  return 13; // 3
        case 4:  return 0; // 4
        case 5:  return 1; // 5
        case 6:  return 2; // 6
        case 7:  return 3; // 7
        case 11: return 8; // J
        case 12: return 9; // Q
        case 13: return 10; // K
        default: return -1;
    }
}

int main() {
    int N;
    cin >> N;

    int vencedorAdalberto = 0;
    int vencedorBernardete = 0;

    for (int i = 0; i < N; i++) {
        int A1, A2, A3, B1, B2, B3;
        cin >> A1 >> A2 >> A3 >> B1 >> B2 >> B3;

        int vencedorRodada1 = valorSimbolico(A1) > valorSimbolico(B1) ? 1 : (valorSimbolico(A1) == valorSimbolico(B1) ? 1 : -1);
        int vencedorRodada2 = valorSimbolico(A2) > valorSimbolico(B2) ? 1 : (valorSimbolico(A2) == valorSimbolico(B2) ? 1 : -1);
        int vencedorRodada3 = valorSimbolico(A3) > valorSimbolico(B3) ? 1 : (valorSimbolico(A3) == valorSimbolico(B3) ? 1 : -1);

        int vencedorPartida = (vencedorRodada1 + vencedorRodada2 + vencedorRodada3) > 0 ? 1 : ((vencedorRodada1 + vencedorRodada2 + vencedorRodada3) == 0 ? 0 : -1);

        if (vencedorPartida == 1) {
            vencedorAdalberto++;
        } else if (vencedorPartida == -1) {
            vencedorBernardete++;
        }
    }

    cout << vencedorAdalberto << " " << vencedorBernardete << endl;

    
return 0;
}