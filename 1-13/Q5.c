#include <stdio.h>

#define SIZE 100

void insert(int arr[], int *n, int element, int pos) {
    if (pos > *n || pos < 0) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = element;
    (*n)++;
}

void delete(int arr[], int *n, int pos) {
    if (pos >= *n || pos < 0) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[SIZE], n, element, pos, choice;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element and position to insert: ");
                scanf("%d %d", &element, &pos);
                insert(arr, &n, element, pos);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete(arr, &n, pos);
                break;
            case 3:
                display(arr, n);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
