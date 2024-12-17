#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, T;
    cin >> N >> T;

    vector<int> up(N), down(N);
    for (int i = 0; i < N; i++) {
        cin >> up[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> down[i];
    }

    vector<bool> flip(N, false);
    for (int i = 0; i < T; i++) {
        int I, J;
        cin >> I >> J;
        I--; J--; // 0-indexed
        for (int k = I; k <= J; k++) {
            flip[k] = !flip[k];
        }
    }

    for (int i = 0; i < N; i++) {
        if (flip[i]) {
            cout << down[i] << " ";
        } else {
            cout << up[i] << " ";
        }
    }
    cout << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}