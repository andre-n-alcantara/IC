#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> flechas(N);
    for (int i = 0; i < N; i++) {
        cin >> flechas[i].first >> flechas[i].second;
    }

    int penalidadeTotal = 0;
    for (int i = 0; i < N; i++) {
        int distancia = flechas[i].first * flechas[i].first + flechas[i].second * flechas[i].second;
        int penalidade = 0;
        for (int j = 0; j < i; j++) {
            int distanciaJ = flechas[j].first * flechas[j].first + flechas[j].second * flechas[j].second;
            if (distanciaJ <= distancia) {
                penalidade++;
            }
        }
        penalidadeTotal += penalidade;
    }

    cout << penalidadeTotal << endl;

    
return 0;
}