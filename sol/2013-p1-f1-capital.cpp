
#include <iostream>
using namespace std;

int main() {
    int A1, A2, A3, A4;
    cin >> A1 >> A2 >> A3 >> A4;
    int areas[4] = {A1, A2, A3, A4};
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            int otherAreas = A1 + A2 + A3 + A4 - areas[i] - areas[j];
            if (areas[i] + areas[j] == otherAreas) {
                cout << "S" << endl;
                return 0;
            }
        }
    }
    cout << "N" << endl;
    return 0;
}
