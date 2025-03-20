#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string findRoot(const string& word) {
    int n = word.size();
    for (int len = 1; len * len <= n; len++) {
        if (n % len == 0) {
            string root = word.substr(0, len);
            bool isPoligram = true;
            for (int i = len; i < n; i += len) {
                string sub = word.substr(i, len);
                sort(root.begin(), root.end());
                sort(sub.begin(), sub.end());
                if (root != sub) {
                    isPoligram = false;
                    break;
                }
            }
            if (isPoligram) {
                return root;
            }
        }
    }
    return "*";
}

int main() {
    int N;
    cin >> N;
    string word;
    cin >> word;
    cout << findRoot(word) << endl;
    return 0;
}