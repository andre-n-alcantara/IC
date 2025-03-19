#include <ctime>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int n, m;
    cin >> n >> m;

    int x = 0, y = 0;
    bool flagged = false;

    for (int i = 0; i < n; i++) {
        char dir;
        int dist;
        cin >> dir >> dist;

        switch (dir) {
            case 'N':
                y += dist;
                break;
            case 'S':
                y -= dist;
                break;
            case 'L':
                x += dist;
                break;
            case 'O':
                x -= dist;
                break;
        }

        double distance = sqrt(x * x + y * y);
        if (distance > m) {
            flagged = true;
            break;
        }
    }

    cout << (flagged ? 1 : 0) << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}