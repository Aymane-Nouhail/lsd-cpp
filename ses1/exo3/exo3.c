#include "exo3.h"

int main(){
    int y;
    printf("Enter a number to check the MSB : \n");
    scanf("%d",&y);
    checkmsb(y);
    unsigned char x;
    printf("\n");
    printf("Enter a a positive integer to convert to 8-bit binary : ");
    scanf("%d",&x);
    printbits(x);
    return 0;
}