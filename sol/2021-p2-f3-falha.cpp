
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countPairs(vector<string>& passwords) {
    int count = 0;
    for (int i = 0; i < passwords.size(); ++i) {
        for (int j = i + 1; j < passwords.size(); ++j) {
            if (passwords[j].find(passwords[i]) != string::npos) {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    vector<string> passwords(N);
    for (int i = 0; i < N; ++i) {
        cin >> passwords[i];
    }
    cout << countPairs(passwords) << endl;
    return 0;
}
