#include <ctime>
#include <iostream>
using namespace std;

int main() {
    int A1, B1, A2, B2, A, B;
    cin >> A1 >> B1 >> A2 >> B2 >> A >> B;

    if ((A1 == A && (B1 + B2 == B)) || (B1 == A && (A1 + A2 == B)) ||
        (A2 == A && (B1 + B2 == B)) || (B2 == A && (A1 + A2 == B)) ||
        (A1 == B && (B1 + A2 == A)) || (B1 == B && (A1 + A2 == A)) ||
        (A2 == B && (B1 + A2 == A)) || (B2 == B && (A1 + A2 == A)))
        cout << "S" << endl;
    else
        cout << "N" << endl;

    
return 0;
}