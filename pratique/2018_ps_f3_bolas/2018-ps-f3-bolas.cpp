#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> bolas(8);
    for (int i = 0; i < 8; i++) {
        cin >> bolas[i];
    }

    bool possivel = true;
    for (int i = 0; i < 7; i++) {
        if (bolas[i] == bolas[i + 1]) {
            bool achou = false;
            for (int j = 0; j < 8; j++) {
                if (i != j && bolas[i] != bolas[j]) {
                    swap(bolas[i + 1], bolas[j]);
                    achou = true;
                    break;
                }
            }
            if (!achou) {
                possivel = false;
                break;
            }
        }
    }

    cout << (possivel ? "S" : "N") << endl;

    return 0;
}