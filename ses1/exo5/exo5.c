#include "exo5.h"

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
    printf("\n");
    int n, m;
    printf("enter the number : ");
    scanf("%d",&m);
    printf("enter which byte : ");
    scanf("%d",&n);
    printf("the byte number %d of %d is : ",n,m);
    print_nth_byte(n, m);
    return 0;
}