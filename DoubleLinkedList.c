//write a c program to implement double linked list 

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertBegin(struct Node** head_ref) {
    int new_data;
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    printf("Enter the data of the new node: ");
    scanf("%d", &new_data);

    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

void insertEnd(struct Node** head_ref) {
    int new_data;
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;

    printf("Enter the data of the new node: ");
    scanf("%d", &new_data);

    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = last;
    if (last != NULL)
        last->next = new_node;
    else
        *head_ref = new_node;
}

void insertAtPos(struct Node** head_ref, int pos) {
    int new_data;
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *temp = *head_ref;

    printf("Enter the data of the new node: ");
    scanf("%d", &new_data);

    if (pos == 1) {
        new_node->data = new_data;
        new_node->next = (*head_ref);
        new_node->prev = NULL;
        if ((*head_ref) != NULL)
            (*head_ref)->prev = new_node;
        (*head_ref) = new_node;
        return;
    }

    for (int i = 0; i < pos - 2 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = new_node;
    temp->next = new_node;
}

void deleteBegin(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    if (*head_ref != NULL)
        (*head_ref)->prev = NULL;
    free(temp);
}

void deleteEnd(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* last = *head_ref;
    if (last->next == NULL) {
        free(last);
        *head_ref = NULL;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->prev->next = NULL;
    free(last);
}

void deleteAtPos(struct Node** head_ref, int pos) {
    if (*head_ref == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head_ref;

    if (pos == 1) {
        *head_ref = temp->next;
        if (*head_ref != NULL)
            (*head_ref)->prev = NULL;
        free(temp);
        return;
    }

    for (int i = 0; i < pos - 2 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    if (temp->next != NULL)
        temp->next->prev = temp;
    free(nodeToDelete);
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, pos;

    while (1) {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete from beginning\n5. Delete from end\n6. Delete from position\n7. Print List\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertBegin(&head);
                break;
            case 2:
                insertEnd(&head);
                break;
            case 3:
                printf("Enter the position: ");
                scanf("%d", &pos);
                insertAtPos(&head, pos);
                break;
            case 4:
                deleteBegin(&head);
                break;
            case 5:
                deleteEnd(&head);
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos);
                deleteAtPos(&head, pos);
                break;
            case 7:
                printList(head);
                break;
            case 8:
            printList(head);
            printf("Exit SuccessFully");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
1. Insert at beginning
2. Insert at end
3. Insert at position
4. Delete from beginning
5. Delete from end
6. Delete from position
7. Print List
8. Exit
Enter your choice: 1
Enter the data of the new node: 5

1. Insert at beginning
2. Insert at end
3. Insert at position
4. Delete from beginning
5. Delete from end
6. Delete from position
7. Print List
8. Exit
Enter your choice: 2
Enter the data of the new node: 10

1. Insert at beginning
2. Insert at end
3. Insert at position
4. Delete from beginning
5. Delete from end
6. Delete from position
7. Print List
8. Exit
Enter your choice: 3
Enter the position: 3
Enter the data of the new node: 15

1. Insert at beginning
2. Insert at end
3. Insert at position
4. Delete from beginning
5. Delete from end
6. Delete from position
7. Print List
8. Exit
Enter your choice: 8
5 <-> 10 <-> 15 <-> NULL
Exit SuccessFully