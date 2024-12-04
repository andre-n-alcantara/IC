
#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    bool paulaWins = (N % (M + 1)) == 0;
    cout << (paulaWins ? "Paula" : "Carlos") << endl;

    return 0;
}
