#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
 	struct Node *prev;
    int data;
    struct Node *next;
} node;

void insertAtBegin(node **head, node**tail, int item)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = item;
    newnode->prev = NULL;

    if(*head == NULL)
    {
    	newnode->next = NULL;
		*tail = newnode;
    }
    else
    {
    	newnode->next = *head;
    	(*head)->prev = newnode;
    }
    *head = newnode;
}

node * searchInList(node *head, int key)
{
    while((head != NULL) && (head->data != key))
        head = head->next;
    return head;
}


void insertAfterElement(node **head, node **tail, int item, int after)
{
    node *newnode;;
    node *ptr = searchInList(*head, after);
    if (ptr == (node *) NULL)
        return;

	newnode = (node *)malloc(sizeof(node));
    newnode->data = item;
    newnode->next = ptr->next;

	if(ptr->next != NULL)
	{
		(ptr->next)->prev = newnode;
    }
	else
	{
		*tail = newnode;
	}
	newnode->prev = ptr;
	ptr->next = newnode;
}

void insertBeforeElement(node **head, int item, int before)
{
	node *newnode, *ptr;
	ptr=searchInList(*head,before);
	if (ptr==NULL)
		return;
	newnode=(node *)malloc(sizeof(node));
	newnode->data=item;
	if(ptr->prev==NULL)
	{
		newnode->prev=NULL;
		ptr->prev=newnode;
		newnode->next=*head;
		*head=newnode;
	}
	else
	{
		newnode->prev=ptr->prev;
		newnode->next=ptr;
		(ptr->prev)->next=newnode;
		ptr->prev=newnode;
	}
}

void insertAtEnd(node **head, node **tail, int item)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = item;
    newnode->next=NULL;

    if(*head == NULL)
    {
    	*head = newnode;
    	newnode->prev = NULL;
    }
    else
    {
        newnode->prev = *tail;
		(*tail)->next = newnode;
    }
    *tail = newnode;
}

void deleteFromBegin(node **head, node **tail)
{
    node *temp;
    if(*head == NULL)
        return;
    temp = *head;
    if(*head == *tail)
    {
    	*head = *tail = NULL;
    }
   	else
    {
        (temp->next)->prev = NULL;
        *head = (*head)->next;
    }
    free(temp);
}

void deleteAfterElement(node **head, node **tail, int after)
{
    node *temp, *loc;
    loc = searchInList(*head, after);
    if (loc == (node *)NULL)
        return;

    if(loc->next == NULL)
    	printf("There is no element after %d", after);
   	else
	{
		temp = loc->next;
		loc->next = temp->next;
		if(temp->next == NULL)
			*tail = loc;
    }
    free(temp);
}

void deleteBeforeElement(node **head, int before)
{
	node *temp, *curloc;
	temp=*head;
	curloc=searchInList(*head,before);
	if (curloc==NULL)
		return;
	else if((curloc->prev)->prev==NULL)
	{
		temp=curloc->prev;
		curloc->prev=NULL;
		*head=curloc;
		free(temp);
	}
	else
	{
		temp=curloc->prev;
		curloc->prev=temp->prev;
		(temp->prev)->next=curloc;
		free(temp);
	}
}

void deleteFromEnd(node **head, node **tail)
{
    node *temp;
    if(*head == NULL)
        return;

	temp = *tail;
    if(*head == *tail)
    {
        *head = *tail = NULL;
    }
	else
    {
        (temp->prev)->next = NULL;
        *tail = temp->prev;
    }
    free(temp);
}

void deleteList(node **head, node **tail)
{
    node *temp;
    while(*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    *tail = NULL;
}

void traverseInOrder(node *head)
{
    while(head != NULL)
    {
        printf(" %d ", head->data);
        head = head->next;
    }
}

int main(){
    node *head = NULL;
    node *tail = NULL;
    insertAtBegin(&head,&tail,1);
    insertAtBegin(&head,&tail,2);
    insertAtBegin(&head,&tail,3);
    insertAtBegin(&head,&tail,4);
    traverseInOrder(head);
    printf("\n");
    insertAtEnd(&head,&tail,5);
    insertAfterElement(&head,&tail,6,4);
    traverseInOrder(head);
	printf("\n");
	deleteFromBegin(&head,&tail);
	deleteAfterElement(&head,&tail,2);
	deleteFromEnd(&head,&tail);
	traverseInOrder(head);
   
    return 0;
}