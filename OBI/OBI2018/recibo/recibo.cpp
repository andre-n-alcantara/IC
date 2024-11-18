// Guilherme A. Pinto
// Recibo: backtracking, OBI-2018

#include <bits/stdc++.h>
using namespace std;

int bt( int k, int base, int restante ){
  if ( k == 0 and restante == 0 ) return 1;
  if ( k == 0 ) return 0;
  if ( base > restante ) return 0;
  int ret = 0;
  for ( int v = base; v <= restante; v++ )
    ret += bt(k-1,v+1,restante-v);
  return ret;   
}

int main(){
  int R, K;
  
  cin >> R >> K;
  cout << bt(K,1,R) << endl;
  
  return 0;
}
