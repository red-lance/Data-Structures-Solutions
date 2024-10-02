#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = *head;

    if (*head != NULL) {
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newNode;
    } else {
        newNode->next = newNode;  // First node points to itself
    }
    *head = newNode;
}

void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
      printf("Empty List");
    }

    struct Node *last = *head, *d;

    if ((*head)->data == key) {
        while (last->next != *head)
            last = last->next;

        if (*head == last) {
            free(*head);
            *head = NULL;
        } else {
            last->next = (*head)->next;
            free(*head);
            *head = last->next;
        }
        return;
    }

    while (last->next != *head && last->next->data != key)
        last = last->next;

    if (last->next->data == key) {
        d = last->next;
        last->next = d->next;
        free(d);
    }
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
