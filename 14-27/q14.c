// Q14
// Stack operations using Array

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push()
{
    int num;
    if (top == MAX-1)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("Enter number: ");
        scanf("%d", &num);
        top += 1;
        stack[top] = num;
    }
}

void peek()
{
    for (int i = MAX-1; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
    if (top == -1)
    {
        printf("Underflow\n");
    }
}

void main()
{
    printf("*********Stack operations using array*********");
    int choice = 0;

    printf("\n----------------------------------------------\n");
    while (choice != 4)
    {
        printf("Chose one from the below options...\n");
        printf("\n1.Push\n2.Peek\n4.Exit");
        printf("\n Enter your choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            peek();
            break;
        }
        case 4:
        {
            exit(1);
        }
        default:
        {
            printf("Please Enter valid choice ");
        }
        };
    }
}