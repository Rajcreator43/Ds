#include<stdio.h>
struct Raj{
    int sap_id;
    int roll_no;
    char branch[80];
};

void print(struct Raj r){
    printf("%d %d %s",r.sap_id,r.roll_no,r.branch);
}

int main(){
    struct Raj r1={600,123,"Comps"};
    print(r1);
    
    return 0;

}