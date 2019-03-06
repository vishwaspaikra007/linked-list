#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int count=0;

struct node
{
    int data;
    struct node* ptr;
};

int insert (struct node *head,int nodeNo);
int toprint(struct node* head);
int deleteNode(struct node *head,int nodeNo);
//function to print the nodes
int toprint(struct node* head)
{
    struct node* a=NULL;
    struct node* temp=NULL;
    a = head;
    do
    {
        printf("%d",a->data);
        printf("\n");
        temp = a;
        a = a->ptr;
    }while(temp->ptr != NULL);
    printf("Total number of nodes : %d\n",count);
    return 0;
}
//function to add a new node
int insert (struct node *head,int nodeNo)
{
    int start=2;
    struct node* newnode=NULL;
    struct node* temp=NULL;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data for new node");
    scanf("%d",&newnode->data);
    if(nodeNo==1)
    {
        newnode->ptr = head;
        head = newnode;
    }
    else
    {
        temp = head;
        while(start<nodeNo)
        {
            temp = temp->ptr;
            start++;
        }
        newnode->ptr = temp->ptr;
        temp->ptr = newnode;
    }
    count++;
    toprint(head);
    return head;
}
int deleteNode (struct node *head,int nodeNo)
{
    int start=1;
    struct node* lastnode=NULL;
    struct node* temp=NULL;
    lastnode = (struct node*)malloc(sizeof(struct node));
    temp = head;
    if(nodeNo==1)
    {
         head = head->ptr;
    }
    else
    {
        while(start<nodeNo)
        {
            lastnode = temp;
            temp = temp->ptr;
            start++;
        }
        lastnode->ptr = temp->ptr;
    }
    count--;
    toprint(head);
    return head;
}
int main()
{
    char yes;
    int nodeNo;
    struct node* a=NULL;
    struct node* head=NULL;
    struct node* temp=NULL;
    do
    {
        count++;
        yes='a';
        a = (struct node*)malloc(sizeof(struct node));
        printf("enter data : ");
        scanf("%d",&a->data);
        a->ptr = NULL;
        if(head == NULL)
            head = a;
        else
            temp->ptr = a;
        temp = a;
        // for addition of new node
         while ((getchar()) != '\n');
        printf("press Y to insert data in LL : ");
        yes = getchar();
        printf("\n");
    }while(yes=='y'||yes=='Y');
    //to print the nodes
    toprint(head);
    //option to add a new node
    do
    {
        yes='a';
        printf("press i or d to insert or delete a node in LL or n to discard : ");
        fflush(stdin);
        yes = getchar();
        switch(yes)
        {
        case 'i':
            {
                printf("Enter the position where you want to insert a new node");
                scanf("%d",&nodeNo);
                head = insert(head,nodeNo);
                break;
            }
        case 'd':
            {
                printf("Enter the position of the node you want to delete");
                scanf("%d",&nodeNo);
                head = deleteNode(head,nodeNo);
                break;
            }
        }
    }while(yes!='n'||yes!='N');
    return 0;
}

