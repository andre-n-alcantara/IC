#include <ctime>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
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
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}