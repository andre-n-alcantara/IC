#include <ctime>
#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double dist(const Point &p1, const Point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double angle(const Point &p1, const Point &p2, const Point &p3) {
    double a = dist(p1, p2);
    double b = dist(p2, p3);
    double c = dist(p1, p3);
    return acos((a * a + b * b - c * c) / (2 * a * b));
}

bool areCollinear(const Point &p1, const Point &p2, const Point &p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) == (p3.x - p1.x) * (p2.y - p1.y);
}

bool arePerpendicular(const Point &p1, const Point &p2, const Point &p3, const Point &p4) {
    return (p2.x - p1.x) * (p4.x - p3.x) + (p2.y - p1.y) * (p4.y - p3.y) == 0;
}

int main() {
    Point p[7];
    for (int i = 0; i < 7; i++) {
        cin >> p[i].x >> p[i].y;
    }

    bool isPine = true;

    // O ângulo P2P1P3 é agudo (vértice em P1)
    if (angle(p[2], p[0], p[1]) > M_PI / 2) {
        isPine = false;
    }

    // Os segmentos P1P2 e P1P3 têm o mesmo comprimento
    if (dist(p[0], p[1]) != dist(p[0], p[2])) {
        isPine = false;
    }

    // Os pontos P2, P3, P4 e P5 são colineares
    if (!areCollinear(p[1], p[2], p[4])) {
        isPine = false;
    }

    // Os pontos médios dos segmentos P2P3 e P4P5 são coincidentes
    Point mid1 = {(p[1].x + p[2].x) / 2, (p[1].y + p[2].y) / 2};
    Point mid2 = {(p[3].x + p[4].x) / 2, (p[3].y + p[4].y) / 2};
    if (mid1.x != mid2.x || mid1.y != mid2.y) {
        isPine = false;
    }

    // O segmento P2P3 tem comprimento maior que o segmento P4P5
    if (dist(p[1], p[2]) <= dist(p[3], p[4])) {
        isPine = false;
    }

    // Os segmentos P4P6 e P5P7 são perpendiculares ao segmento P2P3
    if (!arePerpendicular(p[1], p[2], p[3], p[5])) {
        isPine = false;
    }
    if (!arePerpendicular(p[1], p[2], p[4], p[6])) {
        isPine = false;
    }

    // Os segmentos P4P6 e P5P7 têm o mesmo comprimento
    if (dist(p[3], p[5]) != dist(p[4], p[6])) {
        isPine = false;
    }

    // Os pontos P1 e P6 devem estar separados pela reta que contém o segmento P2P3
    if ((p[0].x - p[1].x) * (p[5].y - p[2].y) == (p[0].y - p[1].y) * (p[5].x - p[2].x)) {
        isPine = false;
    }

    cout << (isPine ? "S" : "N") << endl;

    
return 0;
}