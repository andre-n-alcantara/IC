
#include <iostream>
#include <vector>

using namespace std;

int minParts(vector<int>& seq) {
    int n = seq.size();
    vector<int> diff(n-1);
    for (int i = 1; i < n; i++)
        diff[i-1] = seq[i] - seq[i-1];

    int parts = 1;
    for (int i = 1; i < n-1; i++) {
        if (diff[i-1] != diff[i]) {
            parts++;
            i--;
        }
    }

    return parts;
}

int main() {
    int n;
    cin >> n;
    vector<int> seq(n);
    for (int i = 0; i < n; i++)
        cin >> seq[i];

    cout << minParts(seq) << endl;

    return 0;
}
