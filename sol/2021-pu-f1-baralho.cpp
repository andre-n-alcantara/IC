
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    map<char, int> copas, espadas, ouros, paus;
    for (int i = 0; i < input.size(); i += 3) {
        char naipe = input[i+2];
        int valor = stoi(input.substr(i, 2));
        if (naipe == 'C') {
            if (copas.find(valor) != copas.end()) {
                copas[valor]++;
            } else {
                copas[valor] = 1;
            }
        } else if (naipe == 'E') {
            if (espadas.find(valor) != espadas.end()) {
                espadas[valor]++;
            } else {
                espadas[valor] = 1;
            }
        } else if (naipe == 'U') {
            if (ouros.find(valor) != ouros.end()) {
                ouros[valor]++;
            } else {
                ouros[valor] = 1;
            }
        } else if (naipe == 'P') {
            if (paus.find(valor) != paus.end()) {
                paus[valor]++;
            } else {
                paus[valor] = 1;
            }
        }
    }

    int faltaCopas = 0, faltaEspadas = 0, faltaOuros = 0, faltaPaus = 0;
    bool erroCopas = false, erroEspadas = false, erroOuros = false, erroPaus = false;
    for (int i = 1; i <= 13; i++) {
        if (copas.find(i) == copas.end()) faltaCopas++;
        else if (copas[i] > 1) erroCopas = true;
        if (espadas.find(i) == espadas.end()) faltaEspadas++;
        else if (espadas[i] > 1) erroEspadas = true;
        if (ouros.find(i) == ouros.end()) faltaOuros++;
        else if (ouros[i] > 1) erroOuros = true;
        if (paus.find(i) == paus.end()) faltaPaus++;
        else if (paus[i] > 1) erroPaus = true;
    }

    cout << (erroCopas ? "erro" : faltaCopas ? to_string(faltaCopas) : "0") << endl;
    cout << (erroEspadas ? "erro" : faltaEspadas ? to_string(faltaEspadas) : "0") << endl;
    cout << (erroOuros ? "erro" : faltaOuros ? to_string(faltaOuros) : "0") << endl;
    cout << (erroPaus ? "erro" : faltaPaus ? to_string(faltaPaus) : "0") << endl;

    return 0;
}
