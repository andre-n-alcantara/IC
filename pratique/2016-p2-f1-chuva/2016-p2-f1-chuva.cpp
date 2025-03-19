#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int N;
    cin >> N;

    vector<int> heights(N);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    int left = 0, right = N - 1;
    int maxLeft = 0, maxRight = 0;
    int water = 0;

    while (left <= right) {
        if (heights[left] < heights[right]) {
            if (heights[left] >= maxLeft) {
                maxLeft = heights[left];
            } else {
                water++;
            }
            left++;
        } else {
            if (heights[right] >= maxRight) {
                maxRight = heights[right];
            } else {
                water++;
            }
            right--;
        }
    }

    cout << water << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}