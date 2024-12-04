#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, I, R;
    cin >> N >> M;
    cin >> I >> R;

    vector<bool> infected(N + 1, false);
    infected[I] = true;

    for (int i = 1; i <= M; i++) {
        int A;
        cin >> A;
        vector<int> participants(A);
        for (int j = 0; j < A; j++) {
            cin >> participants[j];
        }

        bool infected_in_meeting = false;
        for (int j = 0; j < A; j++) {
            if (infected[participants[j]]) {
                infected_in_meeting = true;
                break;
            }
        }

        if (infected_in_meeting) {
            for (int j = 0; j < A; j++) {
                infected[participants[j]] = true;
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (infected[i]) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}