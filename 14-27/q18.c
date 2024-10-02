// Q18
// Queue operations using Array

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int front, rear = 0;
int queue[MAX];

void enqueue()
{
    if (rear == MAX)
    {
        printf("Overflow\n");
    }
    else
    {
        int n;
        printf("Enter number: ");
        scanf("%d", &n);
        queue[rear] = n;
        rear++;
    }
}

void dequeue()
{
    if (front == rear)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Deleted element is: %d\n", queue[front]);
        for (int i = 0; i < rear - 1; i++)
        {
            queue[i] = queue[i+1];
        }
        rear--;
    }
}

void display()
{
    if (front == rear)
    {
        printf("Underflow\n");
    }
    else
    {
        for (int i = front; i < rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}

void main()
{
    int choice;
    printf("Queue operations\n");
    while (choice != 4)
    {
        printf("Choose:\n1)Enqueue\n2)Dequeue\n3)Display\n4)Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(1);
        default:
            break;
        }
    }
}