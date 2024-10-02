#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the deque
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Head and tail pointers for the deque
struct Node *front = NULL;
struct Node *rear = NULL;

// Function to check if the deque is empty
int isEmpty()
{
    return (front == NULL);
}

// Function to insert an element at the front of the deque
void insertFront(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Memory overflow\n");
        return;
    }
    temp->data = data;
    temp->next = front;
    temp->prev = NULL;

    if (isEmpty())
    {
        rear = temp; // If the deque was empty, rear also points to the new node
    }
    else
    {
        front->prev = temp;
    }
    front = temp;
    printf("Inserted %d at the front\n", data);
}

// Function to insert an element at the rear of the deque
void insertRear(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Memory overflow\n");
        return;
    }
    temp->data = data;
    temp->next = NULL;
    temp->prev = rear;

    if (isEmpty())
    {
        front = temp; // If the deque was empty, front also points to the new node
    }
    else
    {
        rear->next = temp;
    }
    rear = temp;
    printf("Inserted %d at the rear\n", data);
}

// Function to delete an element from the front of the deque
void deleteFront()
{
    if (isEmpty())
    {
        printf("Deque is empty, cannot delete\n");
        return;
    }

    struct Node *temp = front;
    printf("Deleted %d from the front\n", temp->data);

    front = front->next;

    if (front == NULL)
    { // If there was only one element
        rear = NULL;
    }
    else
    {
        front->prev = NULL;
    }

    free(temp);
}

// Function to delete an element from the rear of the deque
void deleteRear()
{
    if (isEmpty())
    {
        printf("Deque is empty, cannot delete\n");
        return;
    }

    struct Node *temp = rear;
    printf("Deleted %d from the rear\n", temp->data);

    rear = rear->prev;

    if (rear == NULL)
    { // If there was only one element
        front = NULL;
    }
    else
    {
        rear->next = NULL;
    }

    free(temp);
}

// Function to display the elements of the deque
void display()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }

    struct Node *temp = front;
    printf("Deque elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, data;

    do
    {
        printf("\n1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to insert at front: ");
            scanf("%d", &data);
            insertFront(data);
            break;
        case 2:
            printf("Enter the element to insert at rear: ");
            scanf("%d", &data);
            insertRear(data);
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
