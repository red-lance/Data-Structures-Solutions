#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int cqueue[MAX];
int front = -1;
int rear = -1;

void enqueue()
{
    if ((front == rear + 1) || (rear == MAX - 1 && front == 0))
    {
        printf("Overflow\n");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        int n;
        printf("Enter element: ");
        scanf("%d", &n);
        front = rear = 0;
        cqueue[rear] = n;
    }
    else if (rear == MAX - 1 && front != 0)
    {
        int n;
        printf("Enter element: ");
        scanf("%d", &n);
        rear = 0;
        cqueue[rear] = n;
    }
    else
    {
        int n;
        printf("Enter element: ");
        scanf("%d", &n);
        rear++;
        cqueue[rear] = n;
    }
}

void delete()
{
    if (front == -1)
    {
        printf("Underflow\n");
    }
    else if (front == rear)
    {
        printf("Deleted element: %d\n", cqueue[front]);
        front = rear = -1;
    }
    else if (front == MAX - 1)
    {
        printf("Deleted element: %d\n", cqueue[front]);
        front = 0;
    }
    else
    {
        printf("Deleted element: %d\n", cqueue[front]);
        front++;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", cqueue[i]);
        }
    }
    else
    {
        for (int i = front; i < MAX; i++)
        {
            printf("%d ", cqueue[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf("%d ", cqueue[i]);
        }
    }
    printf("\n");
}

int main()
{
    int choice;

    while (choice != 4)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
