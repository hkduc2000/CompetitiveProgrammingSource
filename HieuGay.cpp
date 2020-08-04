#include <stdio.h>
#include <string.h>

int a = 12;
int b = 8;

void hieuGay(){
   if (a>b){
      a -= b;
      hieuGay();
   }
   if (b>a){
      b -= a;
      hieuGay();
   }
}

int main(){
   int c = a*b;
   hieuGay();
   printf("%d", c/a);
}