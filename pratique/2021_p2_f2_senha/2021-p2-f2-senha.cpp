#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    string senha;
    cin >> senha;

    vector<string> palavras(M);
    for (int i = 0; i < M; i++) {
        cin >> palavras[i];
    }

    int P;
    cin >> P;

    vector<string> possiveis_senhas;
    for (char c1 : palavras[0]) {
        for (char c2 : palavras[1]) {
            string temp = senha;
            temp[senha.find('#')] = c1;
            temp[senha.find('#', temp.find('#') + 1)] = c2;
            possiveis_senhas.push_back(temp);
        }
    }

    sort(possiveis_senhas.begin(), possiveis_senhas.end());

    cout << possiveis_senhas[P - 1] << endl;

    
return 0;
}