#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N;
    cin >> N;
    vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        cin >> seq[i];
    }
    
    int maxLen = 0, currLen = 1, last = seq[0];
    for (int i = 1; i < N; i++) {
        if (seq[i] != last) {
            currLen++;
            last = seq[i];
        } else if (i > 1 && seq[i] != seq[i-2]) {
            currLen++;
        } else {
            maxLen = max(maxLen, currLen);
            currLen = 1;
        }
    }
    maxLen = max(maxLen, currLen);
    
    cout << maxLen << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}