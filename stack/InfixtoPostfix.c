#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX 100

int stack_arr[MAX];
char infix[MAX],postfix[MAX];
int top=-1;


int isFull(){
    if(top==MAX-1){
        printf("Stack Overflow\n");
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}

void push(int data){
    if(isFull()){
        printf("Stack Overflow\n");
        return;
    }
    top=top+1;
    stack_arr[top]=data;
}

int pop(){
    int value;
    if(isEmpty()){
        printf("Empty Stack\n");
        exit(1);
    }
    value=stack_arr[top];
    top=top-1;
    return value;
}

void printStack(){
    if(top==-1){
        printf("Empty Stack\n");
        exit(1);
    }
    for(int i=top;i>=0;i--){
        printf("%d \n",stack_arr[i]);
    }
}


void print(){
    int i=0;
    printf("Postfix:- \n");
    while (postfix[i])
    {
        printf("%c",postfix[i]);
        i++;
    }
    printf("\n");
    
}

int precedence(char symbol){
    switch (symbol)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    
    default:
        return 0;
    }
}

void infixtoPost(){
    int j=0;
    int symbol,next;
    for(int i=0;i<strlen(infix);i++){
        symbol=infix[i];

        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while ((next=pop()) != '(')
            {
                postfix[j++]=next;
            }
            break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
                while (!isEmpty() && precedence(stack_arr[top])>=precedence(symbol))
                {
                    postfix[j++]=pop();
                }
                push(symbol);
                break;
        default:
            postfix[j++]=symbol;
            break;
        }
    }
    while (!isEmpty())
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    
}
int post_Eval(){
    int a,b;
    for(int i=0;i<strlen(postfix);i++){
        if(postfix[i]>='0' && postfix[i]<='9'){
            push(postfix[i]-'0');
        }
        else{
            a=pop();
            b=pop();
            switch (postfix[i])
            {
            case '+':
                push(b+a);
                break;
            case '-':
                push(b-a);
                break;
            case '*':
                push(b*a);
                break;
            case '/':
                push(b/a);
                break;
            case '^':
                push(pow(b,a));
                break;
            }
        }
    }
    return pop();
}

int main(){
    int r;
    printf("Enter the infix expression \n");
    gets(infix);
    infixtoPost();
    print();
    r=post_Eval();
    printf("The Answer is %d \n",r);



}