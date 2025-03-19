#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

int min_operations(vector<int>& v) {
    int n = v.size();
    int operations = 0;

    int left = 0, right = n - 1;
    while (left < right) {
        if (v[left] != v[right]) {
            if (v[left] < v[right]) {
                v[left + 1] += v[left];
                left++;
                operations++;
            } else {
                v[right - 1] += v[right];
                right--;
                operations++;
            }
        } else {
            left++;
            right--;
        }
    }

    return operations;
}

int main() {
    std::clock_t startTime = std::clock();
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << min_operations(v) << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}