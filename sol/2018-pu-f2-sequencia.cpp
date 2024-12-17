#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, L, H;
    cin >> N >> L >> H;
    vector<int> seq(N);
    vector<int> marked(N);
    for (int i = 0; i < N; i++) cin >> seq[i];
    for (int i = 0; i < N; i++) cin >> marked[i];

    int max_sum = -1e9;
    int curr_sum = 0;
    int marked_count = 0;

    for (int i = 0; i < N; i++) {
        curr_sum += seq[i];
        if (marked[i]) marked_count++;

        if (marked_count >= L && marked_count <= H) {
            max_sum = max(max_sum, curr_sum);
        }

        if (curr_sum < 0 || marked_count < L) {
            curr_sum = 0;
            marked_count = 0;
        }
    }

    cout << max_sum << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}