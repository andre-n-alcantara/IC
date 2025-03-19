#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int la = a.size(), lb = b.size();
    if (la < lb) {
        for (int i = 0; i < lb - la; i++) {
            a = '0' + a;
        }
    } else if (lb < la) {
        for (int i = 0; i < la - lb; i++) {
            b = '0' + b;
        }
    }

    vector<int> va, vb;
    for (char c : a) {
        va.push_back(c - '0');
    }
    for (char c : b) {
        vb.push_back(c - '0');
    }

    for (int i = va.size() - 1; i >= 0; i--) {
        if (va[i] < vb[i]) {
            va.erase(va.begin() + i);
        } else if (va[i] > vb[i]) {
            vb.erase(vb.begin() + i);
        }
    }

    int ra = -1, rb = -1;
    for (int i : va) {
        ra = ra * 10 + i;
    }
    for (int i : vb) {
        rb = rb * 10 + i;
    }

    if (ra == -1) {
        cout << "-1 ";
    } else {
        cout << ra << " ";
    }
    if (rb == -1) {
        cout << "-1" << endl;
    } else {
        cout << rb << endl;
    }

    
return 0;
}