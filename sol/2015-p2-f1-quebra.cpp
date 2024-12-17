#include <ctime>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Piece {
    int left, right;
    char letter;
};

int main() {
    std::clock_t startTime = std::clock();
    int N;
    cin >> N;

    vector<Piece> pieces(N);
    map<int, int> leftToRight, rightToLeft;

    for (int i = 0; i < N; i++) {
        cin >> pieces[i].left >> pieces[i].letter >> pieces[i].right;
        leftToRight[pieces[i].left] = i;
        rightToLeft[pieces[i].right] = i;
    }

    int current = leftToRight[0];
    string result;

    while (true) {
        result += pieces[current].letter;
        int next = pieces[current].right;
        if (next == 1) break;
        current = leftToRight[next];
    }

    cout << result << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}