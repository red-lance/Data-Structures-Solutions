#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the deque

int deque[MAX];
int front = -1;
int rear = -1;

// Function to insert an element at the front
void insertFront(int value)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1)
    { // First element insertion
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = MAX - 1; // Circularly insert at front
    }
    else
    {
        front--;
    }
    deque[front] = value;
    printf("Inserted %d at front\n", value);
}

// Function to insert an element at the rear
void insertRear(int value)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1)
    { // First element insertion
        front = rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0; // Circularly insert at rear
    }
    else
    {
        rear++;
    }
    deque[rear] = value;
    printf("Inserted %d at rear\n", value);
}

// Function to delete an element from the front
void deleteFront()
{
    if (front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted %d from front\n", deque[front]);
    if (front == rear)
    { // Only one element in the deque
        front = rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0; // Circularly move front
    }
    else
    {
        front++;
    }
}

// Function to delete an element from the rear
void deleteRear()
{
    if (front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted %d from rear\n", deque[rear]);
    if (front == rear)
    { // Only one element in the deque
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1; // Circularly move rear
    }
    else
    {
        rear--;
    }
}

// Function to display the elements of the deque
void display()
{
    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements are: ");
    if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", deque[i]);
        }
    }
    else
    {
        for (int i = front; i < MAX; i++)
        {
            printf("%d ", deque[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf("%d ", deque[i]);
        }
    }
    printf("\n");
}

int main()
{
    int choice, value;

    do
    {
        printf("\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert at front: ");
            scanf("%d", &value);
            insertFront(value);
            break;
        case 2:
            printf("Enter value to insert at rear: ");
            scanf("%d", &value);
            insertRear(value);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (1);

    return 0;
}
