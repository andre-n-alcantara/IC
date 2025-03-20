#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K, P;
    cin >> N >> M >> K >> P;

    string password;
    cin >> password;

    vector<string> words(M);
    for (int i = 0; i < M; ++i) {
        cin >> words[i];
    }

    vector<string> possiblePasswords;
    possiblePasswords.push_back("");

    for (int i = 0; i < M; ++i) {
        vector<string> newPossiblePasswords;
        for (const string& word : words[i]) {
            for (const string& possiblePassword : possiblePasswords) {
                for (char c : word) {
                    newPossiblePasswords.push_back(possiblePassword + c);
                }
            }
        }
        possiblePasswords = newPossiblePasswords;
    }

    for (int i = 0; i < N; ++i) {
        if (password[i] == '#') {
            continue;
        }
        for (string& possiblePassword : possiblePasswords) {
            possiblePassword += password[i];
        }
    }

    sort(possiblePasswords.begin(), possiblePasswords.end());

    cout << possiblePasswords[P - 1] << endl;

    return 0;
}