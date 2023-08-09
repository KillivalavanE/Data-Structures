#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *left;
    int data;
    struct node *right;
    int height;
}*root=NULL;

int nodeHeight(struct node *p){
    int hl,hr;
    hl = p && p->left ? p->left->height:0;
    hr = p&& p->right ? p->right->height:0;
    return hl>hr?hl+1:hr+1;
}

int BalanceFactor(struct node *p){
    int hl,hr;
    hl = p && p->left ? p->left->height:0;
    hr = p&& p->right ? p->right->height:0;
    return hl-hr;
}

struct node * insert(struct node *p,int key){
    struct node *t=NULL;
    if(p==NULL){
        t=malloc(sizeof(struct node));
        t->data=key;
        t->height=1;
        t->left=t->right=NULL;
        return t;
    }
    if(key < p->data){
        p->left=insert(p->left,key);
    }
    else if(key > p->data){
        p->right=insert(p->right,key);
    }
    p->height=node_height(p)
    return p;
}

int main(){

    return 0;
}