#include <stdio.h>

#define MAX 101

int album[MAX];

int main(){
  int N, M, i, fig, res;

  scanf("%d %d", &N, &M);

  for ( i = 1; i <= N; i++ )
    album[i] = 0;

  for ( i = 0; i < M; i++ ){
    scanf("%d", &fig);
    album[fig] = 1;
  }
  
  for ( res = 0, i = 1; i <= N; i++ )
    if ( album[i] == 0 )
      res++;

  printf("%d\n", res);
    
  return 0;
}
