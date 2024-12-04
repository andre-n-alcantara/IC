#include <iostream>
#include <vector>

using namespace std;

int main() {
    int P, N;
    cin >> P >> N;

    vector<int> pos(P, 0);
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        pos[p-1]++;
    }

    bool perfect = true;
    for (int i = 0; i < P; i++) {
        if (pos[i] != 0 && (i == P-1 ? pos[0] == 0 : pos[(i+1)%P] == 0)) {
            perfect = false;
            break;
        }
    }

    cout << (perfect ? "S" : "N") << endl;

    return 0;
}