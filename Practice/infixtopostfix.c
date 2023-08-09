#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char data;
    struct node *next;
}*top=NULL;

void push(char data){
    struct node *t=malloc(sizeof(struct node));
    t->data=data;
    t->next=top;
    top=t;
}

char pop(){
    char x;
    struct node *t=top;
    x=t->data;
    top=top->next;
    free(t);
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
    return 1;
}

int isEmpty(){
    return (top==NULL)?1:0;
}

char * convert(char *infix){
    char *postfix;
    int i=0,j=0;
    int len=strlen(infix);
    postfix=(char*)malloc(sizeof(char)*(len+1));
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
    postfix[j++]='\0';
    printf("%s",strrev(postfix));
}

int main(){
    push('#');
    char infix[]="A*B+C/D";
    convert(strrev(infix)); 
    return 0;
}