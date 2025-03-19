#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N, B;
    cin >> N >> B;
    vector<int> files(N);
    for (int i = 0; i < N; i++) {
        cin >> files[i];
    }
    sort(files.begin(), files.end());
    int folders = 0, currentFolderSize = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (currentFolderSize + files[i] <= B) {
            currentFolderSize += files[i];
        } else {
            folders++;
            currentFolderSize = files[i];
        }
    }
    folders++;
    cout << folders << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}