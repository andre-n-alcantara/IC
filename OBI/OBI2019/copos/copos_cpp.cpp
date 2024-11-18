
#include <iostream>

using namespace std;

int main(){
  int N,m;
  char c;
  
  cin >> N;
  cin >> c;

  int pos[3];
  for (int i=0; i<3; i++)
    pos[i] = 0;
  
  pos[c-'A'] = 1;

  for( int i = 0; i < N; i++ ){
    cin >> m;
    switch( m ){
    case 1:
      swap(pos[0],pos[1]);
      break;
    case 2:
      swap(pos[1],pos[2]);
      break;
    case 3:
      swap(pos[0],pos[2]);
    }
  }

  char res = 'A';
  if ( pos[1] ) res = 'B';
  if ( pos[2] ) res = 'C';
  
  cout << res << endl;
  
  return 0;
}
