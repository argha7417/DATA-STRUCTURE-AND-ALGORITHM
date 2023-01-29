#include<stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}node;

void printmenu();
void insertatbegin();
void traverse();

int main()
{
    int option, item;
    node *head = NULL;
    while(1)
    {
        printmenu();
        scanf("%d",&option);
        switch (option)
        {
            case 1: printf("Enter Item  to insert at begining:");
            scanf("%d",&item);
            insertatbegin(&head, item);
            printf("ITEM ENTERED:");
            break;
            case 2:traverse(head);
            printf("\n");
            break;
            case 0: exit(0);
            default: printf("INVALID OPTION");
        }
    }
    return 0;
}
void printmenu()
{
    printf("OPTIONS AVAILABLE:\n");
    printf("1:  INSERT AT BEGINNING\n");
    printf("2:  TRAVERSE\n");
    printf("0:  TO EXIT\n");
}
/*

HEAD---->DATA|NEXT---->DATA|NEXT---->DATA|NULL
            (NODE ADDRESS)

newnode: notun node banabo jeta
data: node er data part ta 
next: next node er address
malloc(): is used for memory alloccation

*/
void insertatbegin(node **head, int item)
{
    node *newnode=(node* )malloc(sizeof(node));
    newnode->data=item;
    if(*head==NULL)
    newnode->next=NULL;
    else
    newnode->next=*head;
    *head=newnode;
}
void traverse(node *head)
{
	while(head != NULL)
	{
		printf(" %d ", head->data);
		head = head->next;
	}
}
