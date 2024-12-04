#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, B;
    cin >> N >> B;
    vector<int> files(N);
    for (int i = 0; i < N; i++) {
        cin >> files[i];
    }
    sort(files.begin(), files.end());
    int folders = 0, currentFolderSize = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (currentFolderSize + files[i] <= B) {
            currentFolderSize += files[i];
        } else {
            folders++;
            currentFolderSize = files[i];
        }
    }
    folders++;
    cout << folders << endl;
    return 0;
}