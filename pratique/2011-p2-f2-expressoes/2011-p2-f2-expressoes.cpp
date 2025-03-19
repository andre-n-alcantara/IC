#include <ctime>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(const string& s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(') st.push(')');
        else if (c == '[') st.push(']');
        else if (c == '{') st.push('}');
        else if (c == ')' || c == ']' || c == '}') {
            if (st.empty() || st.top() != c) return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    std::clock_t startTime = std::clock();
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        string s;
        cin >> s;
        cout << (isValid(s) ? "S" : "N") << endl;
    }
    
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}