#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Show {
    int start;
    int end;
};

bool compareShows(const Show& a, const Show& b) {
    return a.end < b.end;
}

int maxConsecutiveShows(vector<Show>& shows) {
    sort(shows.begin(), shows.end(), compareShows);

    int maxConsecutive = 1;
    int currentConsecutive = 1;
    int lastEnd = shows[0].end;

    for (int i = 1; i < shows.size(); i++) {
        if (shows[i].start >= lastEnd) {
            currentConsecutive++;
            lastEnd = shows[i].end;
        } else {
            maxConsecutive = max(maxConsecutive, currentConsecutive);
            currentConsecutive = 1;
            lastEnd = shows[i].end;
        }
    }

    maxConsecutive = max(maxConsecutive, currentConsecutive);

    return maxConsecutive;
}

int main() {
    int n;
    cin >> n;

    vector<Show> shows(n);

    for (int i = 0; i < n; i++) {
        cin >> shows[i].start >> shows[i].end;
        // shows[i].end += shows[i].start; // não é necessário converter start time para end time
    }

    cout << maxConsecutiveShows(shows) << endl;

    return 0;
}