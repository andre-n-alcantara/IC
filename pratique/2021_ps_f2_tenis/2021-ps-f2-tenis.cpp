#include <iostream>
#include <algorithm>

int main() {
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;
    int sum = A + B + C + D;
    int diff = INT_MAX;
    for (int a = A; a <= D; a++) {
        for (int b = a; b <= D; b++) {
            int team1 = a + b;
            int team2 = sum - team1;
            if (team1 <= team2) {
                diff = std::min(diff, team2 - team1);
            }
        }
    }
    std::cout << diff << std::endl;
    return 0;
}