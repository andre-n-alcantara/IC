#include <ctime>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
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
            
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
        }
    }

    cout << "sim" << endl;
    return 0;
}