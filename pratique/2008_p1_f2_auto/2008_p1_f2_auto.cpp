#include <iostream>
using namespace std;

int main() {
    int C;
    cin >> C;
    char estrada[C+1];
    cin >> estrada;

    int paineis = 0;
    for (int i = 0; i < C; i++) {
        if (estrada[i] == 'P') paineis += 2;
        else if (estrada[i] == 'C') paineis += 2;
        else if (estrada[i] == 'A') paineis += 1;
        else if (estrada[i] == 'D') paineis += 0;
    }

    cout << paineis << endl;

    return 0;
}