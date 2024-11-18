// Guilherme A. Pinto, OBI-2018, campeonato

#include <bits/stdc++.h>
using namespace std;

string fase[4] {"final", "semifinal", "quartas", "oitavas" };
int A, B;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int j;
  for( int i = 1; i <= 16; i++ ){
    cin >> j;
    if ( j == 1 ) A = i+15;
    if ( j == 9 ) B = i+15;
  }

  int f = 4;

  while( A != B ){
    f--;
    A /= 2;
    B /= 2;
  }
  
  cout << fase[f] << endl;
  
  return 0;
}
