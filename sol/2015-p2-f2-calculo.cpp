
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> addOBI2015(vector<int> x, vector<int> y) {
    vector<int> result;
    int carry = 0;
    for (int i = x.size() - 1, j = y.size() - 1; i >= 0 || j >= 0 || carry; --i, --j) {
        int sum = carry;
        if (i >= 0) sum += x[i];
        if (j >= 0) sum += y[j];
        carry = sum / 2;
        result.push_back(sum % 2);
    }
    reverse(result.begin(), result.end());
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    return result;
}

int main() {
    int M, N;
    cin >> M >> N;
    vector<int> x(M);
    for (int i = 0; i < M; ++i) {
        cin >> x[i];
    }
    vector<int> y(N);
    for (int i = 0; i < N; ++i) {
        cin >> y[i];
    }
    vector<int> result = addOBI2015(x, y);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
