// Q15
// Stack operations using Array

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push()
{
    if (top == MAX - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        int n;
        printf("Enter number: ");
        scanf("%d", &n);
        top += 1;
        stack[top] = n;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        top -= 1;
    }
}

void main()
{
    int choice;
    printf("Stack operations\n");
    while (choice != 3)
    {
        printf("Choose:\n1)Push\n2)Pop\n3)Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            exit(1);

        default:
            break;
        }
    }
}