#include<stdio.h>

int main(){
    int h;
    scanf("%d", &h);
    int fs = h-1;
    int ss = h-1;
    while (fs>0){
        char line[2*h-1];
        line[fs] = '*';
        line[ss] = '*';
        line[2*h-1] = '\0';
        printf("%s", line);
    }
}