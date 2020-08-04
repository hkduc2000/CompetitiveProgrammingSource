#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   system("cls");
   //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
   int a[7];
   int n = 0;
   for (int i = 0; i < 7; i++) {
      int inp;
      scanf("%d", &inp);
      if (inp > 9 && inp < 100) {
         a[n++] = inp;
      }
   }
   for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
         if (a[i] < a[j])
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
         }
      }
   }
   int b[n];
   for (int i = 0; i < n; i++) {
      b[i] = 1;
   }
   for (int i = 1; i < n; i++) {
      if (a[i] == a[i - 1]) {
         b[i] += b[i - 1];
      }
   }

   // Fixed Do not edit anything here.
   printf("\nOUTPUT:\n");
   //@STUDENT: WRITE YOUR OUTPUT HERE:
   bool printed = false;
   for (int cnt = 7; cnt >= 1; cnt--) {
      for (int i = 0; i < n; i++) {
         if (b[i] == cnt) {
            printf("%d ", a[i]);
            printed = true;
         }
         if (printed) break;
      }
   }
   if (printed == false) {
      printf("no two-digit number");
   }

   //--FIXED PART - DO NOT EDIT ANY THINGS HERE
   printf("\n");
   system("pause");
   return (0);
}