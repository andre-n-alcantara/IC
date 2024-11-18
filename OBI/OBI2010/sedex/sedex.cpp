#include <iostream>

using namespace std;

int main(void){
	int a,b;
	cin >> a;
	bool ok=true;
	for(int i = 0; i < 3; i++) ok = ok && (cin >> b, a<=b);
	cout << (ok ? "S":"N") << endl;

	return 0;
}

