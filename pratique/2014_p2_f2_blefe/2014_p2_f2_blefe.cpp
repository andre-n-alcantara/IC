#include <ctime>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    set<int> A;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        A.insert(num);
    }

    vector<int> B;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        B.push_back(num);
    }

    bool valid = true;
    for (int i = 0; i < M; i++) {
        if (A.count(B[i])) continue;

        bool found = false;
        for (int j = 0; j < i; j++) {
            if (A.count(B[i] - B[j])) {
                found = true;
                break;
            }
        }

        if (!found) {
            cout << B[i] << endl;
            
return 0;
        }
    }

    cout << "sim" << endl;
    return 0;
}