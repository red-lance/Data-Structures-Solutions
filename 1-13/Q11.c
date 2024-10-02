#include <stdio.h>
#include <stdlib.h>

// Singly Linked List Node
struct Node {
    int data;
    struct Node* next;
};

// Doubly Linked List Node
struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

// Function to insert into Singly Linked List
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to search in Singly Linked List
int search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key)
            return 1;
        current = current->next;
    }
    return 0;
}

// Function to display Singly Linked List
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(head, key))
                    printf("Found!\n");
                else
                    printf("Not found!\n");
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
