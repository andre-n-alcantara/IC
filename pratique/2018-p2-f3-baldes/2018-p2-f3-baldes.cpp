#include <ctime>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, M;
    cin >> N >> M;

    vector<int> buckets(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> buckets[i];
    }

    for (int i = 0; i < M; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int P, I;
            cin >> P >> I;
            buckets[I] += P;
        } else {
            int A, B;
            cin >> A >> B;
            set<int> weights;
            for (int j = A; j <= B; j++) {
                weights.insert(buckets[j]);
            }
            int maxDiff = 0;
            for (int j = *weights.begin(); j <= *weights.rbegin(); j++) {
                for (int k = j + 1; k <= *weights.rbegin(); k++) {
                    maxDiff = max(maxDiff, abs(j - k));
                }
            }
            cout << maxDiff << endl;
        }
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}