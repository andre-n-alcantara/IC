#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }
    sort(L.begin(), L.end());
    int area = L[0] * L[1];
    for (int i = 2; i < N; i++) {
        if (L[i] != L[0] && L[i] != L[1]) {
            cout << "N" << endl;
            return 0;
        }
    }
    cout << "S" << endl;
    return 0;
}