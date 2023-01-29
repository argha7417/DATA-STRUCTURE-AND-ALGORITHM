#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;          // Data 
    struct node *next; // Address 
}*head;

void createList();
void traverseList();

int main()
{
    createList();

    printf("\nData in the list \n");
    traverseList();

    return 0;
}

void createList()
{
    struct node *temp;
    int control;

    head = (struct node *)malloc(sizeof(struct node));

    if(head == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }


    printf("Enter the data for first node:\t ");
    scanf("%d", &head->data);
    head->next = NULL;   //SLL Property
    
    printf("Want More? Press 1 (for Yes) or Press 0 (for No)\t");
    scanf("%d", &control);
    
    temp = head;
    while(control) 
    {
        temp->next = (struct node *)malloc(sizeof(struct node));
        temp = temp->next; 
        printf("Enter the data of node\t");
        scanf("%d", &temp->data);
        
        printf("Want More? Press 1 (for Yes) or Press 0 (for No)\t");
        scanf("%d", &control);
    }
    temp->next = NULL;   //SLL Property
}


void traverseList()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.");
        return;
    }
    
    temp = head;
    while(temp != NULL)
    {
        printf("%5d -> ", temp->data); // Print data of current node
        temp = temp->next;                 // Move to next node
    }
    printf(" NULL");
}