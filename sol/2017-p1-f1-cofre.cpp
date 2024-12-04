#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> barra(N);
    for (int i = 0; i < N; i++) {
        cin >> barra[i];
    }

    vector<int> seq(M);
    for (int i = 0; i < M; i++) {
        cin >> seq[i];
    }

    vector<int> count(10, 0);
    for (int i = 0; i < M - 1; i++) {
        int start = min(seq[i], seq[i + 1]);
        int end = max(seq[i], seq[i + 1]);
        for (int j = start; j <= end; j++) {
            count[barra[j - 1]]++;
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << count[i] << " ";
    }
    cout << endl;

    return 0;
}