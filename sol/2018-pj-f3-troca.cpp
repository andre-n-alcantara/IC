
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

    vector<bool> flip(N, false);
    for (int i = 0; i < T; i++) {
        int I, J;
        cin >> I >> J;
        I--; J--; // 0-indexed
        for (int k = I; k <= J; k++) {
            flip[k] = !flip[k];
        }
    }

    for (int i = 0; i < N; i++) {
        if (flip[i]) {
            cout << down[i] << " ";
        } else {
            cout << up[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
