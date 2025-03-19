#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

struct Rect {
    int x1, y1, x2, y2;
};

int minDistance(vector<Rect>& rects, Point start, Point end) {
    int dx = abs(end.x - start.x);
    int dy = abs(end.y - start.y);
    int minDist = dx + dy;

    for (const Rect& rect : rects) {
        if (start.x >= rect.x1 && start.x <= rect.x2 && start.y >= rect.y1 && start.y <= rect.y2) {
            if (end.x >= rect.x1 && end.x <= rect.x2 && end.y >= rect.y1 && end.y <= rect.y2) {
                minDist = 0;
                break;
            }
        }

        if (start.x >= rect.x1 && start.x <= rect.x2) {
            int dyLocal = abs(end.y - rect.y1);
            if (dyLocal < dy) {
                dx = abs(end.x - start.x);
                dy = dyLocal;
                minDist = dx + dy;
            }
        }

        if (start.y >= rect.y1 && start.y <= rect.y2) {
            int dxLocal = abs(end.x - rect.x1);
            if (dxLocal < dx) {
                dx = dxLocal;
                dy = abs(end.y - start.y);
                minDist = dx + dy;
            }
        }
    }

    return minDist;
}

int main() {
    int xi, yi, xf, yf, n;
    cin >> xi >> yi >> xf >> yf;
    Point start = {xi, yi};
    Point end = {xf, yf};

    cin >> n;
    vector<Rect> rects(n);
    for (int i = 0; i < n; i++) {
        cin >> rects[i].x1 >> rects[i].y1 >> rects[i].x2 >> rects[i].y2;
    }

    cout << minDistance(rects, start, end) << endl;

    
return 0;
}