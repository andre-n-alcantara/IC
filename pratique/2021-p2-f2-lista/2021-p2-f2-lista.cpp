#include <iostream>
#include <vector>

using namespace std;

int minOperations(vector<int>& nums) {
    int n = nums.size();
    int res = 0;
    int i = 0, j = n - 1;

    while (i < j) {
        if (nums[i] == nums[j]) {
            i++;
            j--;
        } else if (nums[i] < nums[j]) {
            nums[i + 1] += nums[i];
            i++;
            res++;
        } else {
            nums[j - 1] += nums[j];
            j--;
            res++;
        }
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << minOperations(nums) << endl;

    return 0;
}