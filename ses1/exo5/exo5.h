#include<stdio.h>
#include<stdlib.h>

/* prototypes */

void checkmsb(int);
void printbits(unsigned char);
void print_nth_byte(int, int);

/*            */

void checkmsb (int num){
    int bits = sizeof(int)*8;
    int one = 1 << (bits-1);
    if(one & num) printf("msb is set");
    else printf("msb is not set");
    return;
}


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


