#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int minJumps(vector<int> lajotas) {
    int n = lajotas.size();
    vector<int> jumps(n, n);
    jumps[0] = 0;
    for (int i = 1; i < n; i++) {
        if (lajotas[i] == 1) {
            for (int j = max(0, i - 2); j < i; j++) {
                if (lajotas[j] == 1) {
                    jumps[i] = min(jumps[i], jumps[j] + 1);
                }
            }
        }
    }
    return jumps.back() == n ? -1 : jumps.back();
}

int main() {
    int C;
    cin >> C;
    vector<int> lajotas(C);
    for (int i = 0; i < C; i++) {
        cin >> lajotas[i];
    }
    cout << minJumps(lajotas) << endl;
    
return 0;
}