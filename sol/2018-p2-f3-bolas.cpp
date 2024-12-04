
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> bolas(8);
    for (int i = 0; i < 8; i++) {
        cin >> bolas[i];
    }

    sort(bolas.begin(), bolas.end());

    bool pode = true;
    for (int i = 0; i < 7; i++) {
        if (bolas[i] == bolas[i + 1]) {
            pode = false;
            break;
        }
    }

    if (pode) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}
