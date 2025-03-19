#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string p, a;
    cin >> p >> a;

    map<char, int> mp, ma;
    for (char c : p) mp[c]++;
    for (char c : a) {
        if (c == '*') continue;
        ma[c]++;
    }

    bool is_anagram = true;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (ma[it->first] < it->second) {
            is_anagram = false;
            break;
        }
    }

    cout << (is_anagram ? "S" : "N") << endl;

    return 0;
}