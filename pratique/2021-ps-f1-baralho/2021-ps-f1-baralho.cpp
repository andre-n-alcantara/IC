#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    map<char, int[13]> deck;
    deck['C'][0] = deck['E'][0] = deck['U'][0] = deck['P'][0] = 13;

    for (int i = 0; i < input.size(); i += 3) {
        char naipe = input[i+2];
        int valor = (input[i] - '0') * 10 + (input[i+1] - '0');
        if (--deck[naipe][valor-1] < 0) deck[naipe][0] = -1; // duplicada
    }

    for (char naipe : {'C', 'E', 'U', 'P'}) {
        if (deck[naipe][0] == -1) cout << "erro" << endl;
        else cout << 13 - deck[naipe][0] << endl;
    }

    return 0;
}