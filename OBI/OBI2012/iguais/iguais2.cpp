#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define MAX 10005

int main(){
	int N;
	int v[MAX];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> v[i];
	int best = 0;
	for (int i = 0; i < N; i++){
		int j = i;
		for (; j < N && v[i] == v[j]; j++);
		best = max(best, j-i);
	}
	cout << best << endl;
	return 0;
}
