#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N;
    cin >> N;
    vector<int> arcs(N);
    for (int i = 0; i < N; i++) {
        cin >> arcs[i];
    }

    bool ok = false;
    for (int i = 0; i < N; i++) {
        int a = arcs[i];
        int b = arcs[(i + 1) % N];
        int c = arcs[(i + 2) % N];
        int d = arcs[(i + 3) % N];
        if (a == c && b == d) {
            ok = true;
            break;
        }
    }

    cout << (ok ? "S" : "N") << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}