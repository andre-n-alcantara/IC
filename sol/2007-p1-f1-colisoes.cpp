#include <ctime>
#include <iostream>

using namespace std;

bool intersect(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x1 > x2) && (x0 < x3) && (y1 > y2) && (y0 < y3);
}

int main() {
    std::clock_t startTime = std::clock();
    int x0, y0, x1, y1, x2, y2, x3, y3;
    while (cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
        cout << (intersect(x0, y0, x1, y1, x2, y2, x3, y3) ? 1 : 0) << endl;
    }
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}