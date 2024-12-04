
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> consultas(n);
    for (int i = 0; i < n; i++) {
        cin >> consultas[i].first >> consultas[i].second;
    }
    sort(consultas.begin(), consultas.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    int quantidade = 1;
    int fim = consultas[0].second;
    for (int i = 1; i < n; i++) {
        if (consultas[i].first >= fim) {
            quantidade++;
            fim = consultas[i].second;
        }
    }
    cout << quantidade << endl;
    return 0;
}
