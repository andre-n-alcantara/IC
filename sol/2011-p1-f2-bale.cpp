#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::cin >> N;
    std::vector<int> skills(N);
    for (int i = 0; i < N; i++) {
        std::cin >> skills[i];
    }
    std::vector<int> sortedSkills = skills;
    std::sort(sortedSkills.begin(), sortedSkills.end());
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (skills[i] == sortedSkills[N - 1] && skills[j] == sortedSkills[N - 2]) {
                count++;
            } else if (skills[i] == sortedSkills[N - 2] && skills[j] == sortedSkills[N - 1]) {
                count++;
            }
        }
    }
    std::cout << count << std::endl;
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}