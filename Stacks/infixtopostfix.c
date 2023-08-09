#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char data;
    struct node *next;
}*top=NULL;

void push(char x){
    struct node *t=malloc(sizeof(struct node));
    if(t==NULL){
        printf("Stack is full\n");
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

char pop(){
    char x;
    if(top==NULL){
        printf("Stack is empty\n");
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

char * infixtopostfix(char *infix){
    char *postfix;
    int i=0,j=0;
    int len=strlen(infix);
    postfix = (char *)malloc((len+1)*sizeof(char));
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(precedence(infix[i])>precedence(top->data)){
                push(infix[i++]);
            }
            else{
                postfix[j++]=pop();
            }
        }
    }
    while(top->next!=NULL){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    
    return postfix;
}

int isEmpty(){
    return top==NULL?0:1;
}

int main(){
    push('#');
    char str[100];
    printf("Enter the expression in infix to convert to postfix: ");
    scanf("%[^\n]s",str);
    char *postfix = infixtopostfix(str);
    printf("%s ",postfix);
    return 0;
}