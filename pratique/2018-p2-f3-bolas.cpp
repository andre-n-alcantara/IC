#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    vector<int> bolas(8);
    for (int i = 0; i < 8; i++) {
        cin >> bolas[i];
    }

    sort(bolas.begin(), bolas.end());

    bool pode = true;
    for (int i = 0; i < 7; i++) {
        if (bolas[i] == bolas[i + 1]) {
            pode = false;
            break;
        }
    }

    if (pode) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}