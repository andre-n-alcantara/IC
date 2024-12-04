
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> weights(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += weights[i];
    }
    int halfSum = sum / 2;
    bool possible = false;
    for (int i = 0; i < N; i++) {
        int currSum = 0;
        for (int j = i; j < N; j++) {
            currSum += weights[j];
            if (abs(currSum - (sum - currSum)) <= 8 && currSum <= halfSum) {
                possible = true;
                break;
            }
        }
        if (possible) break;
    }
    cout << (possible ? "S" : "N") << endl;
    return 0;
}
