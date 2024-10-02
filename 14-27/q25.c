#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

// Enqueue function to insert an element into the queue
void enqueue(int value)
{
    struct Node *newNode = createNode(value);

    if (front == NULL)
    { // First insertion
        front = rear = newNode;
        rear->next = front; // Circular linking
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Circular linking
    }
    printf("Inserted %d\n", value);
}

// Dequeue function to remove an element from the queue
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
    }
    else if (front == rear)
    { // Only one element in the queue
        printf("Deleted element: %d\n", front->data);
        free(front);
        front = rear = NULL;
    }
    else
    {
        struct Node *temp = front;
        printf("Deleted element: %d\n", front->data);
        front = front->next;
        rear->next = front; // Maintain circular link
        free(temp);
    }
}

// Display the queue
void display()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    struct Node *temp = front;
    printf("Queue elements are: ");
    while (temp->next != front)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data); // Print last element (rear element)
}

int main()
{
    int choice, value;

    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
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
