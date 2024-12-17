#include <ctime>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    std::clock_t startTime = std::clock();
    string input;
    getline(cin, input);
    stringstream ss(input);
    int p_A_h, p_A_m, c_B_h, c_B_m, p_B_h, p_B_m, c_A_h, c_A_m;
    ss >> p_A_h >> p_A_m >> c_B_h >> c_B_m >> p_B_h >> p_B_m >> c_A_h >> c_A_m;

    int p_A = p_A_h * 60 + p_A_m;
    int c_B = c_B_h * 60 + c_B_m;
    int p_B = p_B_h * 60 + p_B_m;
    int c_A = c_A_h * 60 + c_A_m;

    int duration = (c_B - p_A + (c_B - p_A >= 0 ? 0 : 1440)) % 1440;
    if (duration < 0) duration += 1440;

    int offset = (p_B - c_A + (p_B - c_A >= 0 ? 0 : 1440)) % 1440;
    if (offset < 0) offset += 1440;

    cout << duration << " " << (offset / 60) << endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}