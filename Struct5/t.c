#include<stdio.h>
struct point{
    int x;
    int y;
    struct point *ptr;
};
int main(){
    struct point var1,var2;
    var1.x=4;
    var1.y=5;
    var1.ptr=NULL;

    var2.x=1;
    var2.y=8;
    var2.ptr=NULL;

    var1.ptr=&var2;

    printf("%d %d \n",var1.ptr->x,var1.ptr->y);


    return 0;
}