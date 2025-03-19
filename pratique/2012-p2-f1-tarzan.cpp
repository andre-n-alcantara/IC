#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N, D;
vector<pii> trees;

bool canReach(int x, int y) {
    for (auto tree : trees) {
        int dx = abs(tree.first - x);
        int dy = abs(tree.second - y);
        if (dx * dx + dy * dy <= D * D) return true;
    }
    return false;
}

int main() {
    std::clock_t startTime = std::clock();
    cin >> N >> D;
    trees.resize(N);
    for (int i = 0; i < N; i++) cin >> trees[i].first >> trees[i].second;

    bool canTravel = true;
    for (auto tree : trees) {
        if (!canReach(tree.first, tree.second)) {
            canTravel = false;
            break;
        }
    }

    cout << (canTravel ? "S" : "N") << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}