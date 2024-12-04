
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> files(N);
    for (int i = 0; i < N; i++) {
        cin >> files[i];
    }

    int min_chars = INT_MAX;
    for (int i = 0; i < N; i++) {
        string ref = files[i];
        int chars = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            string rel_path;
            size_t pos = files[j].find(ref);
            if (pos != string::npos) {
                rel_path = files[j].substr(pos + ref.size());
            } else {
                int level_up = 0;
                while (files[j].find(ref) == string::npos) {
                    files[j] = "../" + files[j];
                    level_up++;
                }
                rel_path = files[j].substr(level_up * 3);
            }
            chars += rel_path.size();
        }
        min_chars = min(min_chars, chars);
    }
    cout << min_chars << endl;
    return 0;
}
