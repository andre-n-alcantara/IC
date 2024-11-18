#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> m,dp;
int N;

int main(){

  cin >> N;

  m = vector<vector<int>>(N+1,vector<int>(N+1));
  dp = vector<vector<int>>(N+1,vector<int>(N+1));
  
  for ( int i = 1; i <= N; i++ )
    for ( int j = 1; j <= N; j++ )
      cin >> m[i][j];

  for ( int i = 1; i <= N; i++ )
    for ( int j = i; j <= N; j++ ){
      
      dp[i][j] = 0;
      for ( int k = j; k > j-i; k-- )
	dp[i][j] += m[i][k];

      if ( i > 1 ) dp[i][j] += min( dp[i-1][j], dp[i-1][j-1] );
    }
  
  cout << dp[N][N] << endl;
  
  return 0;
}
