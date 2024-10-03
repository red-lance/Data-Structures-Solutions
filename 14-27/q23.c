#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int data;
    int priority;
} PQElement;

PQElement pq[MAX];
int size = 0;

void insert(int value, int priority)
{
    if (size == MAX)
    {
        printf("Priority Queue Overflow\n");
        return;
    }

    pq[size].data = value;
    pq[size].priority = priority;
    size++;

    printf("Inserted value: %d with priority: %d\n", value, priority);
}

void deleteHighestPriority()
{
    if (size == 0)
    {
        printf("Priority Queue Underflow\n");
        return;
    }

    int highestPriorityIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (pq[i].priority < pq[highestPriorityIndex].priority)
        {
            highestPriorityIndex = i;
        }
    }

    printf("Deleted element: %d with priority: %d\n", pq[highestPriorityIndex].data, pq[highestPriorityIndex].priority);

    for (int i = highestPriorityIndex; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    size--;
}

void display()
{
    if (size == 0)
    {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue elements are:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Value: %d, Priority: %d\n", pq[i].data, pq[i].priority);
    }
}

int main()
{
    int choice, value, priority;

    do
    {
        printf("\n1. Insert\n2. Delete (Highest Priority)\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("Enter its priority (lower number = higher priority): ");
            scanf("%d", &priority);
            insert(value, priority);
            break;
        case 2:
            deleteHighestPriority();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (1);

    return 0;
}
