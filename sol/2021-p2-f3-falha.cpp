#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countPairs(vector<string>& passwords) {
    int count = 0;
    for (int i = 0; i < passwords.size(); ++i) {
        for (int j = i + 1; j < passwords.size(); ++j) {
            if (passwords[j].find(passwords[i]) != string::npos) {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    std::clock_t startTime = std::clock();
    int N;
    cin >> N;
    vector<string> passwords(N);
    for (int i = 0; i < N; ++i) {
        cin >> passwords[i];
    }
    cout << countPairs(passwords) << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}