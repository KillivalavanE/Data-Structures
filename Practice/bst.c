#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data){
    struct node *t=malloc(sizeof(struct node));
    t->data=data;
    t->left=t->right=NULL;
    return t;
}

struct node *insert(struct node* root,int data){
    if(root==NULL){
        return create_node(data);
    }
    if(data < root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}

int search(struct node *root,int data){
    struct node* t=root;
    while(root!=0){
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

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

struct node *minvaluenode(struct node *t){
    while(t && t->left!=NULL){
        t=t->left;
    }
    return t;
}

struct node *delete(struct node *root,int data){
    if(root==NULL){
        return root;
    }
    if(data < root->data){
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
        struct node *temp=minvaluenode(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
    }
    return root;
}

struct node *maxi(struct node *root){
    while(root && root->right!=NULL){
        root=root->right;
    }
    return root;
}


struct node *mini(struct node *root){
    while(root && root->left!=NULL){
        root=root->left;
    }
    return root;
}

void maxmin(struct node *root){
    struct node *p=maxi(root);
    struct node *q=mini(root);
    printf("Maximum and Minimum elements in the BST are %d and %d",p->data,q->data);
}
int main(){
    struct node *root=NULL;
    int ch,data;
        while(1)
        {
            printf("\n------------------------");
            printf("\n1. Insert");
            printf("\n2. Maximum and Minimum");
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
                            scanf("%d",&data);
                            root=insert(root,data);
                            break;
                        }
                case 2:
                        {
                            maxmin(root);
                            break;
                        }
                case 3:
                        {
                            printf("Enter the element to search: ");
                            scanf("%d",&data);
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