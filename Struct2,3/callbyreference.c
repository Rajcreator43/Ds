#include<stdio.h>
struct point{
    int x;
    int y;
};
void print(struct point *ptr){
    printf("%d  %d ",ptr->x,ptr->y);
}
int main(){
    struct point p1={4,5};
    struct point p2={1,8};
    print(&p1);
    print(&p2);

    return 0;
}