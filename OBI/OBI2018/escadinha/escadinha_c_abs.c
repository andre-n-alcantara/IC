#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

int s[MAX];

int main(){
  int N, i, res, dif, ndif;

  scanf("%d", &N);
  for ( i = 0; i < N; i++ )
    scanf("%d", &s[i]);
  
  res = 1;
  if ( N > 1 ) dif = abs(s[1]-s[0]);

  for ( i = 1; i < N-1; i++ )
    if ( (ndif = abs(s[i+1]-s[i])) != dif ){
      dif = ndif;
      res++;
    }
  
  printf("%d\n",res);
  
  return 0;
}
