#include <stdio.h>

int main() {
   int N;
   scanf(" %d", &N);
   if (N <= 10) {
      printf("%d\n", 7);
   } else if (N <= 30) {
      printf("%d\n", 7 + (N - 10));
   } else if (N <= 100) {
      printf("%d\n", 27 + 2 * (N - 30));
   } else {
      printf("%d\n", 167 + 5 * (N - 100));
   }
   return 0;
}

