#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, string> phoneMap = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

bool match(string phone, string word) {
    for (int i = 0; i < phone.size(); i++) {
        if (phoneMap[phone[i]].find(word[i]) == string::npos) {
            return false;
        }
    }
    return true;
}

int main() {
    string phone;
    int M;
    cin >> phone;
    cin >> M;

    vector<string> words(M);
    for (int i = 0; i < M; i++) {
        cin >> words[i];
    }

    int count = 0;
    for (const string& word : words) {
        if (match(phone, word)) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}