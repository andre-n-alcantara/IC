
#include <iostream>
#include <vector>

using namespace std;

int countRectangles(vector<int>& arr, int k) {
    int n = arr.size();
    int count = 0;
    vector<int> prefixSum(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = prefixSum[j + 1] - prefixSum[i];
            if (sum == k) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << countRectangles(arr, k) << endl;

    return 0;
}
