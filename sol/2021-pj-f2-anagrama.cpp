#include <ctime>
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::cin >> N;
    std::string a, b;
    std::cin >> a >> b;

    std::string sa, sb;
    for (char c : a) {
        if (isalpha(c)) sa += tolower(c);
    }
    for (char c : b) {
        if (isalpha(c)) sb += tolower(c);
    }

    std::sort(sa.begin(), sa.end());
    std::sort(sb.begin(), sb.end());

    std::cout << (sa == sb ? "S" : "N") << std::endl;

    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}