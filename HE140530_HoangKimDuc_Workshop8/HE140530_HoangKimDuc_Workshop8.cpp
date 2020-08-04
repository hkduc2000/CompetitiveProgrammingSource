#include <stdio.h>
#include <string.h>

bool isPrime[10];

void
   swap(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

int main() {
   int TC;
   printf("1. Run TC 1\n2. Run TC 2\nEnter TC <0 to exit>: ");
   scanf("%d", &TC);
   if (TC==0) return(0);
   if (TC==1){
      int a,b,c;
      printf("Enter a = ");
      scanf("%d", &a);
      printf("Enter b = ");
      scanf("%d", &b);
      printf("Enter c = ");
      scanf("%d", &c);
      if (a>b) swap(&a,&b);
      if (a>c) swap(&a,&c);
      if (b>c) swap(&b,&c);
      printf("\nOUTPUT:\n");
      printf("a = %d, b = %d, c = %d", a, b ,c);
      return(0);
   }
   if (TC==2){
      int m,n, s = 0;
      printf("Enter m = ");
      scanf("%d", &m);
      printf("Enter n = ");
      scanf("%d", &n);
      if (n<m){
         s = (n+1)*(n)/2;
      } else {
         isPrime[2] = isPrime[3] = isPrime[5] = isPrime[7] = true;
         while (n>0){
            int digit = n%10;
            n /= 10;
            if (isPrime[digit]){
               s += digit;
            }
         }
      }
      printf("s = %d\n", s);
      printf("\nOUTPUT\n");
      printf("%d", s);
   }
}