#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, F;
    cin >> N >> F;
    vector<int> capsules(N);
    for (int i = 0; i < N; i++) {
        cin >> capsules[i];
    }
    int days = 0;
    int coins = 0;
    while (coins < F) {
        days++;
        for (int i = 0; i < N; i++) {
            if (days % capsules[i] == 0) {
                coins++;
            }
        }
    }
    cout << days << endl;
    return 0;
}