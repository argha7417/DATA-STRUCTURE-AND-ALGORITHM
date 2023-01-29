#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	struct Node *next;
} node;

void printMenu();
void insertAtBegin(node **head, int item);
void insertAfterElement(node **head, int item, int after);
void insertAtEnd(node **head, int item);
void deleteFromBegin(node **head);
void deleteAfterElement(node **head, int after);
void deleteFromEnd(node **head);
void deleteList(node **head);
void traverseInOrder(node *head);
void traverseInReverseOrder(node *head);
void reverseList(node **head);

node *searchInList(node *head, int key);

int main(void)
{
	int option, item, after, key;
	node *head = NULL, *nd, *preloc, *curloc;

	while(1)
	{
		printMenu();
		scanf("%d", &option);
		switch(option)
		{
			case 1: printf("Enter item to insert at begining :");
					scanf("%d", &item);
					insertAtBegin(&head, item);
					printf("Item inserted\n");
					break;
			case 2: printf("Enter item to insert :");
					scanf("%d", &item);
					printf("Enter item after which one element will be added :");
					scanf("%d", &after);
					insertAfterElement(&head, item, after);
					printf("Item inserted\n");
					break;
			case 3: printf("Enter item to insert at end :");
					scanf("%d", &item);
					insertAtEnd(&head, item);
					printf("Item inserted\n");
					break;
			case 4: deleteFromBegin(&head);
					printf("Item deleted\n");		
					break;
			case 5: printf("Enter item after which one element will be deleted :");
					scanf("%d", &after);
					deleteAfterElement(&head, after);
					printf("Item deleted\n");
					break;
			case 6: deleteFromEnd(&head);
					printf("Item deleted\n");
					break;
			case 7: deleteList(&head);
					printf("List deleted\n");
					break;
			case 8: traverseInOrder(head);
					printf("\n");
					break;
			case 9: traverseInReverseOrder(head);
					printf("\n");
					break;
			case 10:printf("Enter key to search :");
					scanf("%d", &key);
					nd = searchInList(head, key);
					if (nd==NULL)
						printf("Key is not in the list\n");
					else
						printf("Key is in the list\n");
					break;
			case 0: exit(0);
			default: printf("Invalid option");
		}
	}
	return 0;
}

void printMenu()
{
	printf("Chose option\n");
	printf("	1: insert at begin\n");
	printf("	2: insert after an element\n");
	printf("	3: insert at end\n");
	printf("	4: delete from begining\n");
	printf("	5: delete after an element\n");
	printf("	6: delete from end\n");
	printf("	7: delete list\n");
	printf("	8: traverse in order\n");
	printf("	9: traverse in reverse order\n");
	printf("	10: search a key in list\n");
}

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

void insertAfterElement(node **head, int item, int after)
{
	node *newnode;
	node *curloc = searchInList(*head, after);
	if (curloc == (node *) NULL)
		return;
	newnode = (node *)malloc(sizeof(node));
	newnode->data = item;
	newnode->next = curloc->next;
	curloc->next= newnode;
}

void insertAtEnd(node **head, int item)
{
	node *temp;
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = item;
	newnode->next=NULL;

	if(*head == NULL)
		*head = newnode;
	else
	{
		temp = *head;
		while(temp->next != NULL)
			temp = temp->next;

		temp->next = newnode;
	}
}

void deleteFromBegin(node **head)
{
	node *temp;
	if(*head == NULL)
		return;
	else
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

void deleteAfterElement(node **head, int after)
{
	node *temp, *loc;
	loc = searchInList(*head, after);
	if (loc == (node *)NULL)
		return;
	temp = loc->next;
	loc->next = temp->next;
	free(temp);
}

void deleteFromEnd(node **head)
{
	node *temp, *loc;
	if(*head == NULL)
		return;
	else if((*head)->next == (node *)NULL)
	{
		temp = *head;
		*head = NULL;
		free(temp);
	}else
	{
		loc = *head;
		temp = (*head)->next;
		while(temp->next != NULL)
		{
			loc = temp;
			temp = temp->next;
		}
		loc->next = NULL;
		free(temp);
	}
}

void deleteList(node **head)
{
	node *temp;
	while(*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

void traverseInOrder(node *head)
{
	while(head != NULL)
	{
		printf(" %d ", head->data);
		head = head->next;
	}
}

void traverseInReverseOrder(node *head)
{
	if(head->next != NULL)
		traverseInReverseOrder(head->next);
	printf(" %d ", head->data);
}

node * searchInList(node *head, int key)
{
	while((head != NULL) && (head->data != key))
		head = head->next;
	return head;
}