
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool pode_subir(vector<int>& pesos) {
    int sum = 0;
    for (int peso : pesos) {
        sum += peso;
    }

    int avg = sum / pesos.size();

    for (int peso : pesos) {
        if (abs(peso - avg) > 8) {
            return false;
        }
    }

    return true;
}

int main() {
    int N;
    cin >> N;

    vector<int> pesos(N);
    for (int i = 0; i < N; i++) {
        cin >> pesos[i];
    }

    sort(pesos.begin(), pesos.end());

    if (pode_subir(pesos)) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}
