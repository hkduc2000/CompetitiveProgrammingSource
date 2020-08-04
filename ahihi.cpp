#include <stdio.h>
#include <string.h>
int main() {
   int n;
   printf("Enter size: ");
   scanf("%d", &n);
   char a[n];
   for (int i = 0; i < n; i++) {
      a[i] = ' ';
   }
   char b[n + 1];
   int i = 0, j = n - 1;
   for (i; i < n; i++, j--) {
      strcpy(b, a);
      b[i] = '*';
      b[j] = '*';
      puts(a);
   }
   return 0;
}