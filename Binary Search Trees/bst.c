#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *left;
    int data;
    struct node *right;
}*root=NULL;

void insert(int key){
    struct node *t=root;
    struct node *r,*p;
    if(root==NULL){
        p=malloc(sizeof(struct node));
        p->data=key;
        p->left=p->right=NULL;
        root=p;
        return;
    }
    while(t!=NULL){
        r=t;
        if(key<t->data){
            t=t->left;
        }
        else if(key>t->data){
            t=t->right;
        }
        else{
            return;
        }
    }
    p=malloc(sizeof(struct node));
    p->data=key;
    p->left=p->right=NULL;
    if(key<r->data){
        r->left=p;
    }
    else{
        r->right=p;
    }
}

/*
ALITER METHOD FOR INSERTION (RECURSION)

struct node *insert(struct node *p,int key){
    struct node *t=NULL;
    if(p==NULL){
        t=malloc(sizeof(struct node));
        t->data=key;
        t->left=t->right=NULL;
        return t;
    }
    if(key<p->data){
        p->left=insert(p->left,key);
    }
    else if(key>p->data){
        p->right=insert(p->right,key);
    }

    return p;

}

*/

void inorder(struct node *root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

struct node *search(int key){
    struct node *t=root;
    while(t!=NULL){
        if(key == t->data){
            return t;
        }
        else if(key < t->data){
            t=t->left;
        }
        else{
            t=t->right;
        }
    }
    return NULL;
}

int Height(struct node *p){
    int x,y;
    if(p==NULL){
        return 0;
    }
    x=Height(p->left);
    y=Height(p->right);
    return x>y?x+1:y+1;
}

struct node *InPre(struct node *p){
    while(p && p->right!=NULL){
        p=p->right;
    }
    return p;
}

struct node *InSucc(struct node *p){
    while(p && p->left!=NULL){
        p=p->left;
    }
    return p;
}

struct node *delete(struct node *p,int key){
    struct node *q;
    if(p==NULL){
        return NULL;
    }
    if(p->left==NULL && p->right==NULL){
        if(p==root){
            root=NULL;
        }
        free(p);
        return NULL;
    }

    if(key<p->data){
        p->left=delete(p->left,key);
    }
    else if(key>p->data){
        p->right=delete(p->right,key);
    }
    else{   
        if(Height(p->left)>Height(p->right)){
            q=InPre(p->left);
            p->data=q->data;
            p->left=delete(p->left,q->data);
        }
        else{
            q=InSucc(p->right);
            p->data=q->data;
            p->right=delete(p->right,q->data);
        }
    }
    return p;
}

int main(){
    insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);

    inorder(root);
    printf("\n");
    struct node *temp=delete(root,10);
    inorder(root);
    return 0;
}