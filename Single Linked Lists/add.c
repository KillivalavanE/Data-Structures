#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node
{
        int data;
        struct node *next;

}*head = NULL,*head1 = NULL,*head2 = NULL;

int create()
{
        head = (struct node *)malloc(sizeof(struct node));
        printf("Enter the first data : ");
        scanf("%d",&head -> data);
        head -> next = NULL;
        struct node *t,*last;
        last = head;

        int i;
label:
        printf("Enter Enter data  or -100 to exit : ");
        scanf("%d",&i);
        if(i != -100)
        {
                t = (struct node *)malloc(sizeof(struct node));

                t -> data = i;
                t -> next = NULL;
                last -> next = t;
                last = t;
        }

        if(i != -100)
                goto label;
}

int create1()
{
        head1 = (struct node *)malloc(sizeof(struct node));
        printf("Enter the first data : ");
        scanf("%d",&head1 -> data);
        head1 -> next = NULL;
        struct node *t,*last1;
        last1 = head1;

        int i;
label:
        printf("Enter Enter data  or -100 to exit : ");
        scanf("%d",&i);
        if(i != -100)
        {
                t = (struct node *)malloc(sizeof(struct node));

                t -> data = i;
                t -> next = NULL;
                last1 -> next = t;
                last1 = t;
        }

        if(i != -100)
                goto label;
}
void display()
{
        struct node *p = head2;
        while(p != NULL)
        {
                printf("%d ",p->data);
                p = p -> next;
        }
        printf("\n");

}
int count()
{
        struct node *p = head;
        int c;

        while(p != 0)
        {
                c++;
                p = p -> next;
        }
        return c;
}
void reverse()
{
        struct node *p = head;
        struct node *r = NULL;
        struct node *s = NULL;
        struct node *p1 = head1;
        struct node *r1 = NULL;
        struct node *s1 = NULL;
        struct node *p2 = head2;
        struct node *r2 = NULL;
        struct node *s2 = NULL;
        
        while(p != 0)
        {
                s = r;
                r = p;
                p = p -> next;
                r -> next = s;
        }
        head = r;
        while(p1 != 0)
        {
                s1 = r1;
                r1 = p1;
                p1 = p1 -> next;
                r1 -> next = s1;
        }
        head1 = r1;
        while(p2!=0){
                s2=r2;
                r2=p2;
                p2=p2->next;
                r2->next=s2;
        }
        head2=r2;
}

int add()
{
        struct node *p = head;
        struct node *q = head1;
        int x = 0;
        while(p != 0 && q != 0)
        {
                struct node *t2 =  (struct node *)malloc(sizeof(struct node));
                struct node *temp=NULL;
                // struct node *last2;
                x += p -> data + q -> data;
                if(x >= 10)
                {
                        t2->data=x%10;
                        t2->next=NULL;
                        if(head2 == NULL)
                        {
                                head2=t2;
                                temp=t2;
                        }
                        else
                        {
                                temp->next=t2;
                                temp=t2;
                        }
                        p = p -> next;
                        q = q -> next;
                        x = 1;
                }
                else
                {
                        t2->data=x;
                        t2->next=NULL;
                        if(head2 == NULL)
                        {
                                head2=t2;
                                temp=t2;
                        }
                        else
                        {
                                temp->next=t2;
                                temp=t2;
                        }
                        x = 0;
                        p = p -> next;
                        q = q -> next;
               }
        }
        if(x==1){
                struct node *t=malloc(sizeof(struct node));
                t->data=x;
                struct node *p=head2;
                while(p->next!=NULL){
                        p=p->next;
                }
                p->next=t;
                t->next=NULL;
        }
}

        int main()
        {
                create();
                create1();
                reverse();
                add();
                reverse();
                display();
        }