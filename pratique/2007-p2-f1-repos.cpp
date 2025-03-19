#include <ctime>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    int C, N;
    cin >> C >> N;

    map<int, int> installed;
    for (int i = 0; i < C; i++) {
        int Pc, Vc;
        cin >> Pc >> Vc;
        installed[Pc] = Vc;
    }

    vector<pair<int, int>> available;
    for (int i = 0; i < N; i++) {
        int Pn, Vn;
        cin >> Pn >> Vn;
        available.push_back({Pn, Vn});
    }

    for (auto &program : available) {
        if (installed.find(program.first) == installed.end() || installed[program.first] < program.second) {
            cout << program.first << " " << program.second << endl;
        }
    }

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}