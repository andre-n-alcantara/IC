#include <iostream>
#include <cmath>

using namespace std;

int main() {
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

    return 0;
}