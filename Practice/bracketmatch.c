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

char topele(){
    if(top==NULL){
        printf("Stack is empty");
    }
    return top->data;
}

int isEmpty(){
    return (top==NULL)?1:0;
}

int matchParanthesis(char a,char b){
    return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'));
}

int match(char *str){
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='[' || str[i]=='{' || str[i]=='('){
            push(str[i]);
        }
        else{
            if(isEmpty()){
                return 0;
            }
            if(matchParanthesis(topele(),str[i])==0){
                return 0;
            }
            else{
                pop();
            }
        }
    }
    return isEmpty();
}

int main(){
    char str[]="{[}]";
    printf("%d",match(str));
    return 0;
}