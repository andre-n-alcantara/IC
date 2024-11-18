#include <iostream>
using namespace std;

#define MAX 1001

int seq[MAX];

int main(){
  int N;
  
  cin >> N;
  for ( int i = 0; i < N; i++ )
    cin >> seq[i];
  
  int res = 1;
  
  for ( int i = 2; i < N; i++ )
    if ( abs(seq[i]-seq[i-1]) != abs(seq[i-1]-seq[i-2]) )
      res++;
  
  cout << res << endl;
  
  return 0;
}
