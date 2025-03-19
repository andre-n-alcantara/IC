#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<bool> graph[N + 1];
    for (int i = 1; i <= N; i++) {
        graph[i].resize(N + 1, true);
    }

    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        graph[U][V] = graph[V][U] = false;
    }

    vector<int> colors(N + 1);
    for (int i = 1; i <= N; i++) {
        colors[i] = i;
    }

    sort(colors.begin() + 1, colors.end(), [](int a, int b) {
        return a * 2 > b * 2;
    });

    int q = 0;
    vector<int> result;
    for (int i = 1; i <= N; i++) {
        bool valid = true;
        for (int j = 0; j < result.size(); j++) {
            if (!graph[colors[i]][result[j]]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            result.push_back(colors[i]);
            q++;
        }
    }

    cout << q << endl;
    for (int i = 0; i < q; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    
return 0;
}