#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> parents(N);
    for (int i = 0; i < N; i++) {
        cin >> parents[i];
    }

    vector<bool> attended(N, false);
    for (int i = 0; i < M; i++) {
        int attendee;
        cin >> attendee;
        attended[attendee - 1] = true;
    }

    unordered_map<int, int> generationCount;
    for (int i = 0; i < N; i++) {
        int generation = 0;
        int current = i;
        while (current != 0) {
            generation++;
            current = parents[current - 1];
        }
        generationCount[generation]++;
    }

    unordered_map<int, int> attendedCount;
    for (int i = 0; i < N; i++) {
        if (attended[i]) {
            int generation = 0;
            int current = i;
            while (current != 0) {
                generation++;
                current = parents[current - 1];
            }
            attendedCount[generation]++;
        }
    }

    for (auto it = generationCount.begin(); it != generationCount.end(); it++) {
        double percentage = (double)attendedCount[it->first] / it->second * 100;
        cout << fixed << setprecision(2) << percentage << " ";
    }
    cout << endl;

    
return 0;
}