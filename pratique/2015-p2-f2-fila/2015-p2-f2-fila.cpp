#include <ctime>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int N, Q;
    cin >> N;
    vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }
    cin >> Q;
    vector<int> answers;
    stack<pair<int, int>> st;
    for (int i = 0; i < Q; ++i) {
        int T, I, X;
        cin >> T >> I >> X;
        if (T == 0) {
            while (!st.empty() && st.top().second < X) {
                st.pop();
            }
            st.push(make_pair(I, X));
        } else {
            int idx = I - 1;
            while (!st.empty() && st.top().first < idx) {
                st.pop();
            }
            if (st.empty() || heights[idx] + X <= st.top().second) {
                answers.push_back(0);
            } else {
                answers.push_back(st.top().first + 1);
            }
        }
    }
    for (int ans : answers) {
        cout << ans << '\n';
    }
    
return 0;
}