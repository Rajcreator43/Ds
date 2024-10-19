#include<stdio.h>
struct Raj{
    int sap_id;
    int roll_no;
    char branch;
};

void print(int* sap_id,int* roll_no,char* branch){
    scanf("%d %d %c",sap_id,roll_no,branch);
}

int main(){
    struct Raj r1;
    print(&r1.sap_id,&r1.roll_no,&r1.branch);
    printf("%d %d %c",r1.sap_id,r1.roll_no, r1.branch);
    
    return 0;

}