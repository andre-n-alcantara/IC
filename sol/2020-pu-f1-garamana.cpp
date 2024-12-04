#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string p, a;
    cin >> p >> a;

    vector<int> count_p(26, 0);
    vector<int> count_a(26, 0);

    for (char c : p) {
        count_p[c - 'a']++;
    }
    for (char c : a) {
        if (c != '*') {
            count_a[c - 'a']++;
        }
    }

    bool is_anagrama = true;
    for (int i = 0; i < 26; i++) {
        if (count_p[i] < count_a[i]) {
            is_anagrama = false;
            break;
        }
    }

    cout << (is_anagrama ? "S" : "N") << endl;

    return 0;
}