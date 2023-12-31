#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node *next;
}*top=NULL;

void push(int x){
    struct node *t=malloc(sizeof(struct node));
    if(t==NULL){
        printf("Stack Overflow");
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop(){
    int x;
    if(top==NULL){
        printf("Stack is empty");
    }
    else{
        struct node *p=top;
        top=top->next;
        x=p->data;
        free(p);
    }
    return x;
}

int precedence(char x){
    if(x=='+' || x=='-'){
        return 1;
    }
    else if(x=='*' || x=='/'){
        return 2;
    }
    return 0;
}

int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/'){
        return 0;
    }
    else{
        return 1;
    }
}

int evaluate(char *postfix){
    int x1,x2,r;
    for(int i=0;postfix[i]!='\0';i++){
        if(isOperand(postfix[i])){
            push(postfix[i]-'0');
        }
        else{
            x2=pop();
            x1=pop();
            switch(postfix[i])
            {
                case '+':
                    r=x1+x2;
                    break;
                case '-':
                    r=x1-x2;
                    break;
                case '*':
                    r=x1*x2;
                    break;
                case '/':
                    r=x1/x2;
                    break;
            }
            push(r);
        }
    }
    return top->data;
}

int main(){
    char *postfix="32-";
    printf("Evaluated Postfix Expression is :%d",evaluate(postfix));
    return 0;
}