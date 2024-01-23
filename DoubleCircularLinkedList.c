#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        struct Node *last = head->prev;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
        last->next = newNode;
        head = newNode;
    }
}

void insertAtLast(int value)
{
    if (head == NULL)
    {
        insertAtBeginning(value);
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;

        struct Node *last = head->prev;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
        last->next = newNode;
    }
}

void insertAtPosition(int value, int position)
{
    if (position <= 0)
    {
        printf("Invalid position\n");
        return;
    }

    if (position == 1)
    {
        insertAtBeginning(value);
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;

        struct Node *current = head;
        for (int i = 1; i < position - 1; i++)
        {
            if (current->next == head)
            {
                printf("Invalid position\n");
                return;
            }
            current = current->next;
        }

        newNode->prev = current;
        newNode->next = current->next;
        current->next->prev = newNode;
        current->next = newNode;
    }
}

void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete from beginning.\n");
    }
    else
    {
        struct Node *last = head->prev;
        if (head == last)
        {
            free(head);
            head = NULL;
        }
        else
        {
            struct Node *temp = head;
            last->next = head->next;
            head = head->next;
            head->prev = last;
            free(temp);
        }
    }
}

void deleteFromLast()
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete from last.\n");
    }
    else
    {
        struct Node *last = head->prev;
        if (head == last)
        {
            free(head);
            head = NULL;
        }
        else
        {
            struct Node *temp = last;
            last->prev->next = head;
            head->prev = last->prev;
            free(temp);
        }
    }
}

void deleteFromPosition(int position)
{
    if (position <= 0 || head == NULL)
    {
        printf("Invalid position or list is empty\n");
    }
    else if (position == 1)
    {
        deleteFromBeginning();
    }
    else
    {
        struct Node *current = head;
        for (int i = 1; i < position; i++)
        {
            if (current->next == head)
            {
                printf("Invalid position\n");
                return;
            }
            current = current->next;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
    }
}

void printList()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct Node *current = head;
        do
        {
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
        printf("\n");
    }
}

int main()
{
    int choice, value, position;

    do
    {
        printf("\n1. Insert at beginning\t");
        printf("2. Insert at last\t");
        printf("3. Insert at any position\t");
        printf("\n4. Delete from beginning\t");
        printf("5. Delete from last\t");
        printf("6. Delete from any position\t");
        printf("\n7. Print linked list\n");

        printf("\n8. Exit\n");
        printf("Enter your choice:\t ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert at beginning: ");
            scanf("%d", &value);
            insertAtBeginning(value);
            break;
        case 2:
            printf("Enter the value to insert at last: ");
            scanf("%d", &value);
            insertAtLast(value);
            break;
        case 3:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            printf("Enter the position to insert at: ");
            scanf("%d", &position);
            insertAtPosition(value, position);
            break;
        case 4:
            deleteFromBeginning();
            break;
        case 5:
            deleteFromLast();
            break;
        case 6:
            printf("Enter the position to delete from: ");
            scanf("%d", &position);
            deleteFromPosition(position);
            break;
        case 7:
            printList();
            break;
        case 8:
        printList();
        printf("\nExit SuccessFully");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 8);

    return 0;
}