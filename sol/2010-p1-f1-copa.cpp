#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    map<char, int> points;
    vector<char> teams = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    
    for (int i = 0; i < 15; i++) {
        int team1Goals, team2Goals;
        char team1, team2;
        
        if (i < 4) {
            team1 = 'A' + (i / 2) * 2;
            team2 = 'A' + (i / 2) * 2 + 1;
        } else if (i < 8) {
            team1 = 'E' + (i - 4) / 2;
            team2 = 'E' + (i - 4) / 2 + 1;
        } else if (i < 12) {
            team1 = 'A' + (i - 8) / 2;
            team2 = 'A' + (i - 8) / 2 + 1;
        } else {
            team1 = 'E' + (i - 12) / 2;
            team2 = 'E' + (i - 12) / 2 + 1;
        }
        
        cin >> team1Goals >> team2Goals;
        
        if (team1Goals > team2Goals) {
            points[team1] += 3;
        } else if (team1Goals < team2Goals) {
            points[team2] += 3;
        } else {
            points[team1] += 1;
            points[team2] += 1;
        }
    }
    
    char winner;
    int maxPoints = 0;
    
    for (char team : teams) {
        if (points[team] > maxPoints) {
            maxPoints = points[team];
            winner = team;
        }
    }
    
    cout << winner << endl;
    
    return 0;
}