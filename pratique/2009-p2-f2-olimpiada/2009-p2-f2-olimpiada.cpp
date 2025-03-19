#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Country {
    int id;
    int gold;
    int silver;
    int bronze;
};

bool compare(const Country& a, const Country& b) {
    if (a.gold != b.gold) return a.gold > b.gold;
    if (a.silver != b.silver) return a.silver > b.silver;
    if (a.bronze != b.bronze) return a.bronze > b.bronze;
    return a.id < b.id;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Country> countries(N + 1);
    for (int i = 0; i <= N; i++) {
        countries[i].id = i;
        countries[i].gold = 0;
        countries[i].silver = 0;
        countries[i].bronze = 0;
    }

    for (int i = 0; i < M; i++) {
        int O, P, B;
        cin >> O >> P >> B;
        countries[O].gold++;
        countries[P].silver++;
        countries[B].bronze++;
    }

    sort(countries.begin() + 1, countries.end(), compare);

    for (int i = 1; i <= N; i++) {
        cout << countries[i].id << " ";
    }
    cout << endl;

    
return 0;
}