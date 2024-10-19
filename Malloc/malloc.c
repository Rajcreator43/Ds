#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter the Number");
    scanf("%d",&n);
    int *ptr=(int *)malloc(n*sizeof(int));
    if(ptr==NULL){
        printf("Memory not Available");
        exit(1);
    }
    for(int i=0;i<n;i++){
        printf("Enter the number %d",(i+1));
        scanf("%d",ptr+i);
    }
    for(int i=0;i<n;i++){
        printf("%d",*(ptr+i));
    }
    return 0;
}