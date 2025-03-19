#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> digits(N);
    for (int i = 0; i < N; i++) {
        cin >> digits[i];
    }

    int max_divisible = -1;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            swap(digits[i], digits[j]);
            int num = 0;
            for (int k = 0; k < N; k++) {
                num = num * 10 + digits[k];
            }
            if (num % 5 == 0 && num > max_divisible) {
                max_divisible = num;
            }
            swap(digits[i], digits[j]);
        }
    }

    if (max_divisible == -1) {
        cout << "-1" << endl;
    } else {
        vector<int> result;
        while (max_divisible > 0) {
            result.push_back(max_divisible % 10);
            max_divisible /= 10;
        }
        reverse(result.begin(), result.end());
        for (int i = 0; i < N; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    
return 0;
}