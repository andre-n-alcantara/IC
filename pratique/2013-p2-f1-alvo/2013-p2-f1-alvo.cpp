#include <ctime>
#include <iostream>
#include <cmath>

int main() {
    int C, T;
    std::cin >> C >> T;

    int radii[C];
    for (int i = 0; i < C; i++) {
        std::cin >> radii[i];
    }

    int total_points = 0;
    for (int i = 0; i < T; i++) {
        int x, y;
        std::cin >> x >> y;
        int points = 0;
        for (int j = 0; j < C; j++) {
            if (std::sqrt(x*x + y*y) <= radii[j]) {
                points++;
            }
        }
        total_points += points;
    }

    std::cout << total_points << std::endl;

    
return 0;
}