#include<stdio.h>
#include<stdlib.h>
int *input(){
    int *ptr=(int *)malloc(5*sizeof(int));
    printf("Enter the number");
    for(int i=0;i<5;i++){
        scanf("%d",ptr+i);
    }
    return ptr;
}
int main(){
    int sum=0;
    int *ptr=input();
    for(int i=0;i<5;i++){
        sum +=*(ptr+i);
    }
    printf("Sum is %d \n",sum);
    free(ptr);
    ptr=NULL;
    return 0;
}