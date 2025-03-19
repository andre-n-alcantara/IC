#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int P[N];
    for (int i = 0; i < N; i++)
        cin >> P[i];
    bool canFinish = true;
    for (int i = 0; i < N - 1; i++)
        if (P[i + 1] - P[i] > M)
            canFinish = false;
    cout << (canFinish ? "S" : "N") << endl;
    return 0;
}