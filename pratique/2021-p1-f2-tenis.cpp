#include <iostream>
#include <algorithm>

int main() {
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    int levels[4] = {A, B, C, D};
    std::sort(levels, levels + 4);

    int team1 = levels[0] + levels[3];
    int team2 = levels[1] + levels[2];

    std::cout << std::abs(team1 - team2) << std::endl;

    return 0;
}