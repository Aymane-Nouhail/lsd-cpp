#include<stdio.h>
#include<stdlib.h>


void printbits(unsigned char byte){
    unsigned char one = 1 << 7;
    for(int i=0;i<8;i++){
        if(one & byte) printf("1");
        else printf("0");
        one = one >> 1;
    }
    return;
}


int main(){
    unsigned char x;
    scanf("%d",&x);
    printbits(x);
    return 0;
}