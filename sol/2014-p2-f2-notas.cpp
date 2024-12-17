#include <ctime>
#include <iostream>
#include <map>

int main() {
    std::clock_t startTime = std::clock();
    int N;
    std::cin >> N;
    
    std::map<int, int> freq;
    int max_freq = 0;
    int max_note = 0;
    
    for (int i = 0; i < N; i++) {
        int note;
        std::cin >> note;
        freq[note]++;
        if (freq[note] > max_freq) {
            max_freq = freq[note];
            max_note = note;
        } else if (freq[note] == max_freq) {
            max_note = std::max(max_note, note);
        }
    }
    
    std::cout << max_note << std::endl;
    
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}