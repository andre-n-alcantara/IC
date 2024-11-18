#include <stdio.h>

main()
{
  int i, n, latas, copos, quebrados = 0;
  
  scanf("%d", &n);
  
  for(i = 0; i < n; i ++) {
    scanf("%d %d", &latas, &copos);
	if (latas > copos)
	  quebrados += copos;
  }
  printf("%d\n", quebrados);
}

