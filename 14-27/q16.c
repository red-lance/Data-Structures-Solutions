// Q16
// Stack implementation using Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *top = NULL;

void push()
{
    Node *temp = (Node *)malloc(sizeof(Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->next = top;
    top = temp;
}

void display()
{
    Node *temp;
    if (top == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

void main()
{
    int choice;
    while (choice != 3)
    {
        printf("1)Push\n2)Display\n3)Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            display();
            break;

        case 3:
            exit(1);

        default:
            break;
        }
    }
}