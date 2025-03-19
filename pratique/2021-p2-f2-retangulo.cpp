#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> lengths(N);
    for (int i = 0; i < N; i++) {
        cin >> lengths[i];
    }
    sort(lengths.begin(), lengths.end());
    int sum = 0;
    for (int i = 0; i < N / 2; i++) {
        sum += lengths[i];
    }
    if (sum * 2 == accumulate(lengths.begin(), lengths.end(), 0)) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }
    return 0;
}