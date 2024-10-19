#include<stdio.h>
struct point{
    int x;
    char c;
};
void print(struct point arr[]){
    for(int i=0;i<2;i++){

    printf("%d %c\n",arr[i].x,arr[i].c);
    }
}
int main(){
    struct point arr[2]={{1,'A'},{2,'B'}};
    print(arr);
    return 0;
}