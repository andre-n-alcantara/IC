#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
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
                    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
                }
            }
        }
    }

    cout << "ok" << endl;
    return 0;
}