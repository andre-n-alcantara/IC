#include <iostream>
using namespace std;

int main() {
    int A, B, C, H, L;
    cin >> A >> B >> C;
    cin >> H >> L;

    if (max(A, max(B, C)) <= max(H, L) && min(A, min(B, C)) <= min(H, L)) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}