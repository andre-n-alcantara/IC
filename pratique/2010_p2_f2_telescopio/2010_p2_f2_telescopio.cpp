#include <ctime>
#include <iostream>
using namespace std;

int main() {
    int A, N;
    cin >> A >> N;

    int count = 0;
    for (int i = 0; i < N; i++) {
        int F;
        cin >> F;
        if (F * A >= 40000000) count++;
    }

    cout << count << endl;

    
return 0;
}