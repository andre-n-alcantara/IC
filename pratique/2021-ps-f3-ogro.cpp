#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int left_hand = min(N, 5);
    int right_hand = max(N - 5, 0);

    for (int i = 0; i < left_hand; i++) {
        cout << "I";
    }
    for (int i = left_hand; i < 5; i++) {
        cout << "*";
    }
    cout << endl;

    if (right_hand > 0) {
        for (int i = 0; i < right_hand; i++) {
            cout << "I";
        }
        for (int i = right_hand; i < 5; i++) {
            cout << "*";
        }
    } else {
        cout << "*";
    }
    cout << endl;

    return 0;
}