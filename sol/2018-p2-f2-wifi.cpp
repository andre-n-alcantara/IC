
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rect {
    int x1, y1, x2, y2;
};

bool intersect(Rect a, Rect b) {
    return a.x1 < b.x2 && a.x2 > b.x1 && a.y1 > b.y2 && a.y2 < b.y1;
}

int main() {
    int n;
    cin >> n;
    vector<Rect> rects(n);
    for (int i = 0; i < n; i++) {
        cin >> rects[i].x1 >> rects[i].y1 >> rects[i].x2 >> rects[i].y2;
    }
    vector<bool> visited(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            ans++;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && intersect(rects[cur], rects[j])) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
