#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, L, H;
    cin >> N >> L >> H;

    vector<int> seq(N);
    vector<int> mark(N);
    for (int i = 0; i < N; i++) {
        cin >> seq[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> mark[i];
    }

    int max_sum = -1e9;
    int curr_sum = 0;
    int marked = 0;

    for (int i = 0; i < N; i++) {
        curr_sum += seq[i];
        if (mark[i]) marked++;

        while (marked > H) {
            curr_sum -= seq[i - marked + H + 1];
            if (mark[i - marked + H + 1]) marked--;
        }

        if (marked >= L) {
            max_sum = max(max_sum, curr_sum);
        }
    }

    cout << max_sum << endl;

    return 0;
}