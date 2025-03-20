#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T, N;
    cin >> T >> N;

    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    sort(X.begin(), X.end());

    double min_vizinhanca = T;
    for (int i = 0; i < N - 1; i++) {
        double vizinhanca = (X[i + 1] - X[i]) / 2.0;
        min_vizinhanca = min(min_vizinhanca, vizinhanca);
    }

    cout << fixed << setprecision(2) << min_vizinhanca << endl;

    return 0;
}