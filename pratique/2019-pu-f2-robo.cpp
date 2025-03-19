#include <ctime>
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

struct Rect {
    Point p1, p2;
};

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool inside(Rect r, Point p) {
    return (p.x >= r.p1.x && p.x <= r.p2.x && p.y >= r.p1.y && p.y <= r.p2.y);
}

int bfs(vector<Rect> &rects, Point start, Point end) {
    queue<Point> q;
    q.push(start);
    vector<vector<bool>> visited(1001, vector<bool>(1001, false));
    visited[start.x][start.y] = true;
    int dist = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            Point p = q.front();
            q.pop();
            if (p.x == end.x && p.y == end.y) return dist;
            for (int j = 0; j < 4; j++) {
                Point np = { p.x + dx[j], p.y + dy[j] };
                if (np.x >= 0 && np.x <= 1000 && np.y >= 0 && np.y <= 1000 && !visited[np.x][np.y]) {
                    bool isInside = false;
                    for (Rect r : rects) {
                        if (inside(r, np)) {
                            isInside = true;
                            break;
                        }
                    }
                    if (!isInside) {
                        visited[np.x][np.y] = true;
                        q.push(np);
                    }
                }
            }
        }
        dist++;
    }
    return -1;
}

int main() {
    std::clock_t startTime = std::clock();
    int xi, yi, xf, yf;
    cin >> xi >> yi >> xf >> yf;
    Point start = { xi, yi }, end = { xf, yf };
    int n;
    cin >> n;
    vector<Rect> rects(n);
    for (int i = 0; i < n; i++) {
        cin >> rects[i].p1.x >> rects[i].p1.y >> rects[i].p2.x >> rects[i].p2.y;
    }
    cout << bfs(rects, start, end) << endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}