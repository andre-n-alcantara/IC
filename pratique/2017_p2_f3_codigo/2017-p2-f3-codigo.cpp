#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> seq(N);
    for (int i = 0; i < N; i++) {
        cin >> seq[i];
    }

    for (int i = 2; i < N; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                string concat = seq[k] + seq[j];
                if (concat.find(seq[i]) != string::npos) {
                    cout << seq[i] << endl;
                    
return 0;
                }
            }
        }
    }

    cout << "ok" << endl;
    return 0;
}