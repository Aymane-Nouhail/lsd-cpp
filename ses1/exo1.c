#include<stdio.h>
#include<stdlib.h>

void checkmsb (int num){
    int bits = sizeof(int)*8;
    int one = 1 << (bits-1);
    if(one & num) printf("msb is set");
    else printf("msb is not set");
    return;
}

int main(){
    int x;
    printf("Enter a number to check the MSB : \n");
    scanf("%d",&x);
    checkmsb(x);
    return 0;
}