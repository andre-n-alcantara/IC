#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int h1, m1, h2, m2, h3, m3, h4, m4;
    char c;
    cin >> h1 >> c >> m1 >> h2 >> c >> m2 >> h3 >> c >> m3 >> h4 >> c >> m4;

    int t1 = h1 * 60 + m1;
    int t2 = h2 * 60 + m2;
    int t3 = h3 * 60 + m3;
    int t4 = h4 * 60 + m4;

    int dt = (t2 - t1 + 1440) % 1440;
    int db = (t4 - t3 + 1440) % 1440;

    int d = (dt + db) / 2;
    int delta = (t2 - t1 - d + 1440) % 1440 / 60;

    cout << d << " " << delta << endl;

    return 0;
}