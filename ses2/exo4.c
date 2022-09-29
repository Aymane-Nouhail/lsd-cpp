#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int* array = (int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array : \n");
    for(int i=0;i<n;i++){
        int m; scanf("%d",&m);
        *(array+i) = m;
    }
    printf("[");
    for(int i=0;i<n;i++) printf("%d, ",*(array+i));
    printf("\b\b]");
    return 0;
}