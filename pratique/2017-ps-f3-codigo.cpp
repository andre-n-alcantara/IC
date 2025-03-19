#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isSubsequence(const string& s1, const string& s2) {
    int i = 0, j = 0;
    while (i < s1.size() && j < s2.size()) {
        if (s1[i] == s2[j]) {
            i++;
        }
        j++;
    }
    return i == s1.size();
}

bool isValidCode(const vector<string>& code) {
    for (int k = 2; k < code.size(); k++) {
        for (int a = 0; a < k - 1; a++) {
            for (int b = a; b < k - 1; b++) {
                if (isSubsequence(code[k], code[a] + code[b])) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<string> code(N);
    for (int i = 0; i < N; i++) {
        cin >> code[i];
    }
    if (isValidCode(code)) {
        cout << "ok" << endl;
    } else {
        for (int k = 2; k < code.size(); k++) {
            for (int a = 0; a < k - 1; a++) {
                for (int b = a; b < k - 1; b++) {
                    if (isSubsequence(code[k], code[a] + code[b])) {
                        cout << code[k] << endl;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}