#include <stdio.h>
#include <stdlib.h>

typedef struct QNode
{
    int data;
    struct QNode *next;
} QNode;

void insert(QNode **front, QNode **rear, int data)
{
    QNode *newNode = (QNode *)malloc(sizeof(QNode));
    newNode->data = data;
    newNode->next = NULL;

    if (*rear == NULL)
    {
        *front = *rear = newNode;
        return;
    }

    (*rear)->next = newNode;
    *rear = newNode;
}

void delete(QNode **front, QNode **rear)
{
    if (*front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    QNode *temp = *front;
    *front = (*front)->next;

    if (*front == NULL)
        *rear = NULL;

    free(temp);
}

void display(QNode *front)
{
    QNode *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    QNode *front = NULL, *rear = NULL;
    int choice, data;

    while (1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &data);
            insert(&front, &rear, data);
            break;
        case 2:
            delete (&front, &rear);
            break;
        case 3:
            display(front);
            break;
        case 4:
            display(front);
            printf("Exit SuccessFully");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}