#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool lampA = false, lampB = false;
    for(int i = 0; i < n; i++) {
        int press;
        cin >> press;
        if(press == 1) {
            lampA = !lampA;
        } else {
            lampA = !lampA;
            lampB = !lampB;
        }
    }
    cout << (lampA ? 1 : 0) << endl;
    cout << (lampB ? 1 : 0) << endl;
    return 0;
}