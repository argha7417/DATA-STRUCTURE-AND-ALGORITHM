#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	struct Node *next;
} node;
/*

HEAD---->DATA|NEXT---->DATA|NEXT---->DATA|NULL
            (NODE ADDRESS)

newnode: notun node banabo jeta
data: node er data part ta 
next: next node er address
malloc(): is used for memory alloccation

*/
void insertAtBegin(node **head, int item)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = item;

	if(*head == NULL)
		newnode->next=NULL;
	else
		newnode->next = *head;

	*head = newnode;
}
void traverseInOrder(node *head)
{
	while(head != NULL)
	{
		printf(" %d ", head->data);
		head = head->next;
	}
}
int main()
{
    node *head=NULL;
    insertAtBegin(&head,12 );
    insertAtBegin(&head,13 );
    insertAtBegin(&head,14 );
    insertAtBegin(&head,15 ); 
    traverseInOrder(head);
    return 0;
}
