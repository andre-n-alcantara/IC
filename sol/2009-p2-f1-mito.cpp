
#include <iostream>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;

    set<pair<int, int>> raios;

    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;
        if (!raios.insert({X, Y}).second) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}
