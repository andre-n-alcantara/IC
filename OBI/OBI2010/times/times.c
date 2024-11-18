#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<int, string> pis;

int main(void){
	int N, T;
	cin >> N >> T;

	vector<pis> vp;

	for(int i = 0; i < N; i++){
		int lvl;
		string nome;
		cin >> nome >> lvl;
		vp.push_back(pis(-lvl, nome));
	}

	sort(vp.begin(), vp.end());

	for(int i = 1; i <= T; i++){
		cout << "Time " << i << endl;
		vector<string> time;

		for(int k = i-1; k < N; k+=T){
			time.push_back(vp[k].second);
		}

		sort(time.begin(), time.end());

		for(int k = 0; k < time.size(); k++){
			cout << time[k] << endl;
		}

		cout << endl;

	}

	return 0;
}

