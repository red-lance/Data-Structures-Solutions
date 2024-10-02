#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a node in circular doubly linked list
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node* last = *head;

    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
        return;
    }

    while (last->next != *head)
        last = last->next;

    last->next = newNode;
    newNode->prev = last;
    newNode->next = *head;
    (*head)->prev = newNode;
}

// Function to delete a node from the circular doubly linked list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL)
        return;

    struct Node *temp = *head, *last = *head;

    while (last->next != *head)
        last = last->next;

    while (temp->data != key) {
        if (temp->next == *head)
            return;
        temp = temp->next;
    }

    if (*head == temp)
        *head = temp->next;

    if (temp == last)
        last = temp->prev;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void display(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("(back to head)\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;
            case 3:
                display(head);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
