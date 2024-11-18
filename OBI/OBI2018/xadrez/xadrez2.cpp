#include <iostream>
using namespace std;

int cordacasa( int l, int c ){
  if ( l > 1 ) return 1-cordacasa( l-1, c );
  if ( c > 1 ) return 1-cordacasa( l, c-1 );
  return 1;  
}

int main(){
  int L, C;
  
  cin >> L >> C;
  cout << cordacasa( L, C ) << endl;
    
  return 0;
}
