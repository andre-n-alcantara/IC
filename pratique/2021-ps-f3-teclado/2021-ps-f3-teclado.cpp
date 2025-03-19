#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, string> keypad = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
                           {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

bool canRepresent(const string& number, const string& str) {
    if (number.size() != str.size()) return false;
    for (int i = 0; i < number.size(); i++) {
        if (keypad[number[i] - '0'].find(tolower(str[i])) == string::npos) return false;
    }
    return true;
}

int main() {
    string number;
    int M;
    vector<string> strs;

    cin >> number;
    cin >> M;

    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        strs.push_back(str);
    }

    int count = 0;
    for (const auto& str : strs) {
        if (canRepresent(number, str)) count++;
    }

    cout << count << endl;

    return 0;
}