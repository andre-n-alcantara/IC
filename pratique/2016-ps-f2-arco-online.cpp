#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> flechas(N);
    vector<int> penalidades(N);

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        if (i > 0) {
            x += penalidades[i-1];
            y += penalidades[i-1];
        }

        flechas[i] = make_pair(x, y);
    }

    for (int i = 0; i < N; i++) {
        int penalidade = 0;
        for (int j = 0; j < i; j++) {
            if (abs(flechas[i].first) >= abs(flechas[j].first) &&
                abs(flechas[i].second) >= abs(flechas[j].second)) {
                penalidade++;
            }
        }
        penalidades[i] = penalidade;
    }

    for (int i = 0; i < N; i++) {
        cout << penalidades[i] << endl;
    }

    return 0;
}