#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
}*root=NULL;

struct node *create_node(int data){
    struct node *t=malloc(sizeof(struct node));
    t->data=data;
    t->left=t->right=NULL;
    return t;
}

struct node *insert(struct node *root,int data){
    if(root==NULL){
        return create_node(data);
    }
    if(data < root->data){
        root->left=insert(root->left,data);
    }
    else if(data > root->data){
        root->right=insert(root->right,data);
    }
    return root;
}

int search(struct node *root,int data){
    while(root!=NULL){
        if(data==root->data){
            return 1;
        }
        else if(data < root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return 0;
}

struct node *minvaluenode(struct node *root){
    while(root && root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct node *delete(struct node *root,int data){
    if(root==NULL){
        return root;
    }
    else if(data < root->data){
        root->left=delete(root->left,data);
    }
    else if(data > root->data){
        root->right=delete(root->right,data);
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
        root->data=t->data;
        root->right=delete(root->right,t->data);
    }
    return root;
}

void inorder(struct node *root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root){
    if(root){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    struct node *root=NULL;
    int ch,data;
    while(1){
        printf("\n.......................");
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Search");
        printf("\n4.Print");
        printf("\n5.Exit");
        printf("\n........................\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            {
                printf("Enter the element to insert: ");
                scanf("%d",&data);
                root=insert(root,data);
                break;
            }
            case 2:
            {
                printf("Enter the element to delete: ");
                scanf("%d",&data);
                root=delete(root,data);
                break;
            }
            case 3:
            {
                printf("Enter the element to search: ");
                scanf("%d",&data);
                int x=search(root,data);
                (x==1)?printf("Element is found"):printf("Element is not found");
                break;
            }
            case 4:
            {
                inorder(root);
                break;
            }
            case 5:
            {
                exit(1);
                break;
            }
        }
    }
    return 0;
}
