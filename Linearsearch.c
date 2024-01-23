

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *newNode(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insertNode(Node **head_ref, int new_data)
{
    Node *new_node = newNode(new_data);
    Node *last = *head_ref;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}

int linear_search(Node *head, int key)
{
    int index = 0;
    while (head != NULL)
    {
        if (head->data == key)
        {
            return index;
        }
        head = head->next;
        index++;
    }
    return -1;
}

int main()
{
    Node *head = NULL;
    int n, key, index;

    printf("Enter the SIZE : ");
    scanf("%d", &n);

    printf("Enter the element : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insertNode(&head, key);
    }

    printf("Enter the key to search for: ");
    scanf("%d", &key);

    index = linear_search(head, key);
    if (index != -1)
    {
        printf("Element found at index %d\n", index);
    }
    else
    {
        printf("Element not found in the linked list\n");
    }

    return 0;
}