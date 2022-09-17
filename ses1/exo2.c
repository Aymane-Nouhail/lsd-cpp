#include<stdio.h>
#include<stdlib.h>


void printbits(unsigned char byte){
    int bits = sizeof(unsigned char)*8;
    unsigned char one = 1 << bits-1;
    for(int i=0;i<bits;i++){
        if(one & byte) printf("1");
        else printf("0");
        one = one >> 1;
    }
    return;
}


int main(){
    unsigned char x;
    printf("Enter a a positive integer to convert to 8-bit binary : ");
    scanf("%d",&x);
    printbits(x);
    return 0;
}