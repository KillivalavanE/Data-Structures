#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

struct node *create_node(int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    return temp;
}

struct node * createlist(){
    int data;
    printf("Enter data: ");
    scanf("%d",&data);
    struct node *head=NULL;
    struct node *temp=NULL;
    do{
        struct node *newnode= create_node(data);
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->link=newnode;
            temp=newnode;
            
        }
        printf("Enter data (-1 to quit) :");
        scanf("%d",&data);
    }while(data!=-1);
    return head;
}

struct node * insert(struct node *head,int x,int pos){
    struct node *t=malloc(sizeof(struct node));
    struct node *p=head;
    t->data=x;
    if(pos==0){
        t->link=head;
        head=t;
        return head;
    }
    if(pos==-1){
        while(p->link!=NULL){
            p=p->link;
        }
        p->link=t;
        t->link=NULL;
        return head;
    }
    else{
        for(int i=0;i<pos-1;i++){
            p=p->link;
        }
        t->link=p->link;
        p->link=t;
        return head;
    }
}

struct node * delete (struct node *head, int position)
{
    struct node *cur = head;
    struct node *tail = NULL;
    if (position == 0)
    {
        return head->link;
    }
    if (position == -1)
    {
        while (cur->link->link!= NULL)
        {
            cur = cur->link;
        }
        struct node *temp=cur->link;
        cur->link=NULL;
        free(temp);
        return head;
    }
    else
    {
        int i = 0;
        while (i < position)
        {
            tail = cur;
            cur = cur->link;
            i++;
        }
        tail->link = cur->link;
        free(cur);
        cur = NULL;
        return head;
    }
}

struct node *reverse(struct node *head){
    struct node *p=head,*q=NULL,*r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->link;
        q->link=r;
    }
    head=q;
    return head;
}

void print(struct node *head){
    struct node *p=head;
    while(p){
        printf("%d ",p->data);
        p=p->link;
    }
}

int main(){
    struct node *head=createlist();
    printf("Linked List: ");
    print(head);
    int ch,data,pos;
        while(1)
        {
            printf("\n------------------------");
            printf("\n1. Insert");
            printf("\n2. Delete");
            printf("\n3. Reverse");
            printf("\n4. Print");
            printf("\n5. Quit");
            printf("\n------------------------");
            printf("\nEnter your choice: ");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                        {
                            printf("Enter the position to be inserted (-1 to insert in last position) :");
                            scanf("%d",&pos);
                            printf("Enter element to be inserted: ");
                            scanf("%d",&data);
                            head=insert(head,data,pos);
                            printf("Linked list after insertion: ");
                            print(head);
                            break;
                        }
                case 2:
                        {
                            printf("Enter the position to be deleted (-1 to delete last element) :");
                            scanf("%d",&pos);
                            head=delete(head,pos);
                            printf("Linked list after deletion: ");
                            print(head);
                            break;
                        }
                case 3:
                        {
                            head=reverse(head);
                            printf("Reversed Linked List: ");
                            print(head);
                            break;
                        }
                case 4:
                        {
                            printf("Linked List: ");
                            print(head);
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