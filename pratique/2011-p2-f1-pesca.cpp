#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N;
    cin >> N;

    vector<pair<int, int>> intervalsX, intervalsY;
    for (int i = 0; i < N; i++) {
        int Xi, Xf, Yi, Yf;
        cin >> Xi >> Xf >> Yi >> Yf;

        intervalsX.push_back({Xi, 1});
        intervalsX.push_back({Xf, -1});
        intervalsY.push_back({Yi, 1});
        intervalsY.push_back({Yf, -1});
    }

    sort(intervalsX.begin(), intervalsX.end());
    sort(intervalsY.begin(), intervalsY.end());

    int area = 0, currX = 0, currY = 0, currCoveredX = 0, currCoveredY = 0;
    for (int i = 0; i < intervalsX.size(); i++) {
        currX += intervalsX[i].second;
        if (currX > 0 && currCoveredX == 0) {
            currCoveredX = intervalsX[i].first;
        } else if (currX == 0 && currCoveredX != 0) {
            area += intervalsX[i].first - currCoveredX;
            currCoveredX = 0;
        }
    }

    for (int i = 0; i < intervalsY.size(); i++) {
        currY += intervalsY[i].second;
        if (currY > 0 && currCoveredY == 0) {
            currCoveredY = intervalsY[i].first;
        } else if (currY == 0 && currCoveredY != 0) {
            area *= intervalsY[i].first - currCoveredY;
            currCoveredY = 0;
        }
    }

    cout << area << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}