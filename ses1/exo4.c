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

void print_nth_byte(int n, int m){
    if(n>4 || n<1){
        printf("byte argument only takes numbers from 1 to 4.\n");
        exit(EXIT_FAILURE);
    }
    //255 = 00000000 00000000 00000000 11111111, we shift the desired byte to the right and do an & operation with 255.
    unsigned char res  = (m>>(8*(n-1))) & 255;
    printbits(res);
}


int main(){
    int n, m;
    printf("enter the number : ");
    scanf("%d",&m);
    printf("enter which byte : ");
    scanf("%d",&n);
    printf("the byte number %d of %d is : ",n,m);
    print_nth_byte(n, m);
    return 0;
}