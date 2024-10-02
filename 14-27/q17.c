// Q17
// Reversing a list of numbers using Stack

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1; 

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

void reverse_list(int list[], int len)
{
    for (int i = 0; i < len; i++)
    {
        push(list[i]);
    }
}

int main()
{
    int list[MAX] = {1, 2, 3, 4, 5};
    int len = sizeof(list) / sizeof(list[0]);

    printf("Original list:\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");

    reverse_list(list, len);

    printf("Reversed list:\n");
    for (int i = MAX - 1; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");

    return 0;
}
