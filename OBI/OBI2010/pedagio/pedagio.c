#include <stdio.h>

int main() {
   int L, D, K, P;
   scanf(" %d %d", &L, &D);
   scanf(" %d %d", &K, &P);
   printf("%d\n", L * K + (L / D) * P);
   return 0;
}

