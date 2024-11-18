// Guilherme A. Pinto, OBI-2018, campeonato

#include <bits/stdc++.h>
using namespace std;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int j,A,B;
  for( int i = 1; i <= 16; i++ ){
    cin >> j;
    if ( j == 1 ) A = i;
    if ( j == 9 ) B = i;
  }
  if ( A > B ) swap( A, B );

  if ( A <= 8 and B > 8 ) {
    cout << "final" << endl;
  } else {
    if ( ( A <= 4 and B > 4 ) or
	 ( A <= 12 and B > 12 ) ) {
      cout << "semifinal" << endl;
    } else {
      if ( ( A <= 2 and B > 2 ) or
	   ( A <= 6 and B > 6 ) or
	   ( A <= 10 and B > 10 ) or
	   ( A <= 14 and B > 14 ) ) {
	cout << "quartas" << endl;
      }	else {
	cout << "oitavas" << endl;
      }
    }
  }
  
  return 0;
}
