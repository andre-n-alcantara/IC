
#include <iostream>

using namespace std;

bool intersect(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x1 > x2) && (x0 < x3) && (y1 > y2) && (y0 < y3);
}

int main() {
    int x0, y0, x1, y1, x2, y2, x3, y3;
    while (cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
        cout << (intersect(x0, y0, x1, y1, x2, y2, x3, y3) ? 1 : 0) << endl;
    }
    return 0;
}
