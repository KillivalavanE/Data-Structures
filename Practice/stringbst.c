#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    struct node *left,*right;
    char *str;
}*root=NULL;

struct node *create_node(char *data){
    struct node *t=(struct node*)malloc(sizeof(struct node));
    t->str=(char *)malloc(sizeof(strlen(data))+1);
    strcpy(t->str,data);
    t->left=t->right=NULL;
    return t;
}

struct node* insert(struct node *root,char *data){
    if(root==NULL){
        return create_node(data);
    }
    if(strcmp(data,root->str)>0){
        root->right=insert(root->right,data);
    }
    else if(strcmp(root->str,data)>0){
        root->left=insert(root->left,data);
    }
    return root;
}

struct node *minvaluenode(struct node *t){
    while(t && t->left!=NULL){
        t=t->left;
    }
    return t;
}

struct node *delete(struct node *root,char *data){
    if(root==NULL){
        return root;
    }
    if(strcmp(data,root->str)>0){
        root->right=delete(root->right,data);
    }
    else if(strcmp(root->str,data)>0){
        root->left=delete(root->left,data);
    }
    else{
        if(root->left==NULL){
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        struct node *t=minvaluenode(root->right);
        strcpy(root->str,t->str);
        root->right=delete(root->right,t->str);
    }
    return root;
}

int search(struct node *root,char *data){
    while(root){
        if(strcmp(data,root->str)==0){
            return 1;
        }
        else if(strcmp(root->str,data)>0){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return 0;
}

void inorder(struct node *root){    
    if(root)
    {
        inorder(root->left);
        printf("%s ",root->str);
        inorder(root->right);
    }
}

int main(){
    struct node *root=NULL;
    int ch;
    char data[100];
        while(1)
        {
            printf("\n------------------------");
            printf("\n1. Insert");
            printf("\n2. Delete");
            printf("\n3. Search");
            printf("\n4. Print");
            printf("\n5. Quit");
            printf("\n------------------------");
            printf("\nEnter your choice: ");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                        {
                            printf("Enter element to insert: ");
                            scanf("%s",data);
                            root=insert(root,data);
                            break;
                        }
                case 2:
                        {
                            printf("Enter element to delete: ");
                            scanf("%s",data);
                            root=delete(root,data);
                            break;
                        }
                case 3:
                        {
                            printf("Enter the element to search: ");
                            scanf("%s",data);
                            int x=search(root,data);
                            (x==1)?printf("Element is found in the tree"):printf("Element is not found in the tree");
                            break;
                        }
                case 4:
                        {
                                printf("Binary Search Tree: ");
                                inorder(root);
                                break;
                        }
                case 5:
                        {
                           exit(1);
                        }
                default:
                        {
                            printf("Invalid choice!!");
                        }
                }
        }
    return 0;
}