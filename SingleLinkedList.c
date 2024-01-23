// write a c program to implement singlelinked

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(struct Node **head, int data, int position)
{
    if (position <= 0)
    {
        printf("Invalid position\n");
        return;
    }

    if (position == 1)
    {
        insertAtBeginning(head, data);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    struct Node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteFromEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void deleteFromPosition(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (position <= 0)
    {
        printf("Invalid position\n");
        return;
    }

    if (position == 1)
    {
        deleteFromBeginning(head);
        return;
    }

    struct Node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    struct Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    int choice, data, position;

    while (1)
    {
        printf("1. Insert at beginning\n");
        printf("2. Insert at last\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from last\n");
        printf("6. Delete from position\n");
        printf("7. Print Linked List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &position);
            insertAtPosition(&head, data, position);
            break;
        case 4:
            deleteFromBeginning(&head);
            break;
        case 5:
            deleteFromEnd(&head);
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &position);
            deleteFromPosition(&head, position);
            break;
        case 7:
            printList(head);
            break;
        case 8:
            printList(head);
           printf("Exit Successfully\n  ");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
