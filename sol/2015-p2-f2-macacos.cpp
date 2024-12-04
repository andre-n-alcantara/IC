#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> trees(N);
    for (int i = 0; i < N; i++) {
        cin >> trees[i].first >> trees[i].second;
    }

    sort(trees.begin(), trees.end());

    int jumps = 0;
    int maxHeight = trees[0].second;
    int lastTree = 0;

    for (int i = 1; i < N; i++) {
        if (trees[i].second > maxHeight) {
            jumps++;
            maxHeight = trees[i].second;
            lastTree = i;
        } else if (trees[i].second == maxHeight) {
            if (trees[i].first > trees[lastTree].first) {
                lastTree = i;
            }
        }
    }

    cout << jumps << endl;

    return 0;
}