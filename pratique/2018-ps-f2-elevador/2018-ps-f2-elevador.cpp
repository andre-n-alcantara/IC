#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> weights(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += weights[i];
        if (sum - weights[i] > 8) {
            cout << "N" << endl;
            return 0;
        }
    }
    cout << "S" << endl;
    return 0;
}