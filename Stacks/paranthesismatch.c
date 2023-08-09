#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
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

char topele(){
        if(top==NULL){
            printf("Stack is empty");
        }
        return top->data;
    }

void display(){
    struct node *p=top;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

bool isBalance(char *p){
    for(int i=0;p[i]!='\0';i++){
        if(p[i]=='(' || p[i]=='{' || p[i]=='[')
            push(p[i]);
        else if((topele()=='(' && p[i]==')') ||(topele()=='{' && p[i]=='}') || (topele()=='[' && p[i]==']')){
            if(top==NULL){
                return false;
            }
            pop();
        }
    }
    return top==NULL?true:false;
}

int main(){
    char *p="{[]}";
    bool res=isBalance(p);
    (res==true) ? printf("Paranthesis is balanced") : printf("Paranthesis is'nt balanced");
    return 0;
}
