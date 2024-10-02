#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the priority queue
struct Node
{
    int data;
    int priority;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data, int priority)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

// Function to insert a node into the priority queue
void insert(struct Node **head, int data, int priority)
{
    struct Node *temp = createNode(data, priority);

    // If the priority queue is empty or the new node has higher priority than the head
    if (*head == NULL || (*head)->priority > priority)
    {
        temp->next = *head;
        *head = temp;
    }
    else
    {
        // Find the appropriate position to insert the new node
        struct Node *current = *head;
        while (current->next != NULL && current->next->priority <= priority)
        {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
    printf("Inserted element %d with priority %d\n", data, priority);
}

// Function to delete the highest priority element (lowest priority number)
void delete(struct Node **head)
{
    if (*head == NULL)
    {
        printf("Priority Queue is empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    printf("Deleted element %d with priority %d\n", temp->data, temp->priority);
    free(temp);
}

// Function to display the priority queue
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("Priority Queue is empty\n");
        return;
    }
    printf("Priority Queue:\n");
    while (head != NULL)
    {
        printf("Element: %d, Priority: %d\n", head->data, head->priority);
        head = head->next;
    }
}

int main()
{
    struct Node *pq = NULL; // Priority queue is initialized as empty
    int choice, data, priority;

    do
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &data);
            printf("Enter its priority: ");
            scanf("%d", &priority);
            insert(&pq, data, priority);
            break;
        case 2:
            delete (&pq);
            break;
        case 3:
            display(pq);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (1);

    return 0;
}
