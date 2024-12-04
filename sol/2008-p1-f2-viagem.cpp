#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, XC, YC, R;
    cin >> N >> XC >> YC >> R;

    int hits = 0;
    for (int i = 0; i < N; i++) {
        int X1, Y1, X2, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;

        double dx = X2 - X1;
        double dy = Y2 - Y1;
        double a = dx * dx + dy * dy;
        double b = 2 * (dx * (X1 - XC) + dy * (Y1 - YC));
        double c = (X1 - XC) * (X1 - XC) + (Y1 - YC) * (Y1 - YC) - R * R;

        double det = b * b - 4 * a * c;
        if (det >= 0) {
            det = sqrt(det);
            double t1 = (-b - det) / (2 * a);
            double t2 = (-b + det) / (2 * a);

            if ((t1 >= 0 && t1 <= 1) || (t2 >= 0 && t2 <= 1)) {
                hits++;
            }
        }
    }

    cout << hits << endl;

    return 0;
}