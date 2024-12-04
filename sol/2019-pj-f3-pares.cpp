
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, I, F;
    cin >> N >> I >> F;

    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int sum = nums[i] + nums[j];
            if (sum >= I && sum <= F) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
