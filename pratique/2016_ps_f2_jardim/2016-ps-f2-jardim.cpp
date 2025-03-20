#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double angle(const Point& p1, const Point& p2, const Point& p3) {
    double a = distance(p2, p1);
    double b = distance(p2, p3);
    double c = distance(p1, p3);
    return acos((a * a + b * b - c * c) / (2 * a * b));
}

bool isCollinear(const Point& p1, const Point& p2, const Point& p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x) == 0;
}

bool isPerpendicular(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    return (p2.x - p1.x) * (p4.x - p3.x) + (p2.y - p1.y) * (p4.y - p3.y) == 0;
}

bool intersects(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    double det = (p2.x - p1.x) * (p4.y - p3.y) - (p2.y - p1.y) * (p4.x - p3.x);
    if (det == 0) return false;
    double t = ((p4.x - p3.x) * (p1.y - p3.y) + (p4.y - p3.y) * (p3.x - p1.x)) / det;
    double u = ((p2.x - p1.x) * (p1.y - p3.y) + (p2.y - p1.y) * (p3.x - p1.x)) / det;
    return 0 <= t && t <= 1 && 0 <= u && u <= 1;
}

int main() {
    Point p[7];
    for (int i = 0; i < 7; i++) {
        cin >> p[i].x >> p[i].y;
    }

    double a = angle(p[2], p[1], p[3]);
    if (a >= M_PI / 2) {
        cout << "N" << endl;
        return 0;
    }

    if (distance(p[1], p[2]) != distance(p[1], p[3])) {
        cout << "N" << endl;
        return 0;
    }

    if (!isCollinear(p[2], p[3], p[4]) || !isCollinear(p[2], p[3], p[5])) {
        cout << "N" << endl;
        return 0;
    }

    Point mid1 = {(p[2].x + p[3].x) / 2, (p[2].y + p[3].y) / 2};
    Point mid2 = {(p[4].x + p[5].x) / 2, (p[4].y + p[5].y) / 2};
    if (mid1.x != mid2.x || mid1.y != mid2.y) {
        cout << "N" << endl;
        return 0;
    }

    if (distance(p[2], p[3]) <= distance(p[4], p[5])) {
        cout << "N" << endl;
        return 0;
    }

    if (!isPerpendicular(p[2], p[3], p[4], p[6]) || !isPerpendicular(p[2], p[3], p[5], p[7])) {
        cout << "N" << endl;
        return 0;
    }

    if (distance(p[4], p[6]) != distance(p[5], p[7])) {
        cout << "N" << endl;
        return 0;
    }

    if (!intersects(p[1], p[6], p[2], p[3])) {
        cout << "N" << endl;
        return 0;
    }

    cout << "S" << endl;

    return 0;
}