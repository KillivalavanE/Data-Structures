#include <stdio.h>
#include <stdlib.h>

int count = 0;

struct node
{
    char data[50];
    struct node *next;
};

struct node *create()
{
    int n = 1;
    struct node *head = NULL;
    struct node *tail = NULL;
    struct node *cur = NULL;
    while (n)
    {
        cur = malloc(sizeof(struct node));

        printf("Enter The Player Name : ");
        scanf("%s%*c", &cur->data);

        if (head == NULL)
        {
            head = tail = cur;
        }
        else
        {
            tail->next = cur;
            tail = cur;
            tail->next = NULL;
        }

        count++;

        printf("Enter 1 to input or 0 to exit : ");
        scanf("%d", &n);
    }

    tail = head;

    return tail;
}

struct node *insert(struct node *head, int position)
{
    if (count < position)
    {
        printf("Invalid Position");
    }
    else
    {
        struct node *tail = head;
        struct node *new = NULL;
        new = malloc(sizeof(struct node));
        printf("Enter The Player Name To Insert : ");
        scanf("%s", &new->data);
        if (position == 0)
        {
            new->next = head;
            head = new;
        }
        if (position == -1)
        {
            while (tail->next != NULL)
            {
                tail = tail->next;
            }
            tail->next = new;
            new->next = NULL;
        }
        else
        {
            int i = 0;
            while (i < position - 1)
            {
                tail = tail->next;
                i++;
            }
            new->next = tail->next;
            tail->next = new;
        }
        return head;
    }
}

struct node * delete (struct node *head, int position)
{
    struct node *cur = head;
    struct node *tail = NULL;
    if (position == 0)
    {
        return head->next;
    }
    if (position == -1)
    {
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        free(cur);
        return head;
    }
    else
    {
        int i = 0;
        while (i < position)
        {
            tail = cur;
            cur = cur->next;
            i++;
        }
        tail->next = cur->next;
        free(cur);
        cur = NULL;
        return head;
    }
}

void print(struct node *tail)
{
    printf("Team Members.....");
    while (tail != NULL)
    {
        printf("%s ", tail->data);
        tail = tail->next;
    }
    printf("\n");
    printf("\n");
}

int main()
{
    struct node *head = create();
    int position;
    print(head);
    int choice = 0;
    printf("Enter Your Choice: \n  0 - Exit  \n  1 - Insert  \n  2 - Delete  \n  3 - Print : ");
    scanf("%d", &choice);
    while (choice)
    {
        switch (choice)
        {
        case 1:
            printf("\nEnter The Position To Insert The Data (-1 to insert to last place): ");
            scanf("%d", &position);
            head = insert(head, position);
            print(head);
            break;
        case 2:
            printf("\nEnter The Position To Delete The Data (-1 to delete last data) : ");
            scanf("%d", &position);
            head= delete (head, position);
            print(head);
            break;
        case 3:
            print(head);
            break;
        }
        printf("Enter Your Choice:\n  0 - Exit \n  1 - Insert Data\n  2 - Delete Data \n  3 - Print Data : ");
        scanf("%d", &choice);
    }
    return 0;
}