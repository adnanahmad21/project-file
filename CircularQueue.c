// write a c program to implement circular queue

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int Q[SIZE];
int front = -1;
int rear = -1;

int isFull()
{
    if ((rear + 1) % SIZE == front)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (front == -1)
    {
        return 1;
    }
    return 0;
}

void insert(int val)
{
    if (isFull())
    {
        printf("Queue is Full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        Q[rear] = val;
        printf("Inserted %d\n", val);
    }
}

void delete()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
        printf("Deleted element\n");
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        int i = front;
        do
        {
            printf("%d ", Q[i]);
            i = (i + 1) % SIZE;
        } while (i != (rear + 1) % SIZE);
        printf("\n");
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            display();
            printf("Exit SuccessFully");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}