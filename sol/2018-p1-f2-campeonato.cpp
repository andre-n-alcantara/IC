#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    vector<int> players(16);
    for (int i = 0; i < 16; i++) {
        cin >> players[i];
    }

    int kungPosition = -1;
    int luPosition = -1;
    for (int i = 0; i < 16; i++) {
        if (players[i] == 1) kungPosition = i + 1;
        if (players[i] == 9) luPosition = i + 1;
    }

    int round = 1;
    while (kungPosition != luPosition) {
        kungPosition = (kungPosition + 1) / 2;
        luPosition = (luPosition + 1) / 2;
        round *= 2;
    }

    if (round == 2) cout << "oitavas" << endl;
    else if (round == 4) cout << "quartas" << endl;
    else if (round == 8) cout << "semifinal" << endl;
    else cout << "final" << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}