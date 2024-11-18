// Guilherme A. Pinto, pulo, OBI-2018

#include <bits/stdc++.h>

using namespace std;

int C;
vector<int> p;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> C;

  p = vector<int>(C);

  for ( int i = 0; i < C; i++ )
    cin >> p[i];

  int pulos = 0;
  int lajota = 0;

  while( lajota < C-1 ){
    // tenta pular duas lajotas
    if ( lajota+2 < C and p[lajota+2] == 1 ){
      pulos++;
      lajota += 2;
    } else {
      // tenta pular uma lajota
      if ( lajota+1 < C and p[lajota+1] == 1 ) {
	pulos++;
	lajota++;
      } else {
	// nao da para pular!
	break;
      }
    }
  }

  if ( lajota == C-1 ) cout << pulos << endl;
  else cout << -1 << endl;
  
  return 0;
}
