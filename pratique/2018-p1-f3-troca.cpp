#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    vector<int> up(N), down(N);
    for (int i = 0; i < N; i++) {
        cin >> up[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> down[i];
    }

    vector<bool> flipped(N, false);
    for (int i = 0; i < T; i++) {
        int I, J;
        cin >> I >> J;
        I--; J--; // ajuste para índice 0-based
        for (int j = I; j <= J; j++) {
            flipped[j] = !flipped[j];
        }
    }

    for (int i = 0; i < N; i++) {
        if (flipped[i]) {
            cout << down[i] << " ";
        } else {
            cout << up[i] << " ";
        }
    }
    cout << endl;

    return 0;
}