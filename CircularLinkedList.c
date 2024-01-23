#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** start_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    if (new_node == NULL) {
        printf("Memory out of space\n");
        return;
    }

    new_node->data = new_data;

    if (*start_ref == NULL) {
        new_node->next = new_node;
        *start_ref = new_node;
    } else {
        new_node->next = (*start_ref)->next;
        (*start_ref)->next = new_node;
        *start_ref = new_node;
    }

    printf("Node inserted\n");
}

void insertAtLast(struct Node** start_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    if (new_node == NULL) {
        printf("Memory out of space\n");
        return;
    }

    new_node->data = new_data;

    if (*start_ref == NULL) {
        new_node->next = new_node;
        *start_ref = new_node;
    } else {
        new_node->next = (*start_ref)->next;
        (*start_ref)->next = new_node;
        *start_ref = new_node;

        struct Node* temp = *start_ref;
        while (temp->next != *start_ref) {
            temp = temp->next;
        }
        temp->next = *start_ref;
    }

    printf("Node inserted\n");
}

void insertAtPosition(struct Node** start_ref, int new_data, int position) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* temp = *start_ref;

    if (new_node == NULL) {
        printf("Memory out of space\n");
        return;
    }

    new_node->data = new_data;

    if (position == 1) {
        if (*start_ref == NULL) {
            new_node->next = new_node;
            *start_ref = new_node;
        } else {
            new_node->next = temp->next;
            temp->next = new_node;
            *start_ref = new_node;
        }
    } else {
        for (int i = 0; i < position - 2; i++) {
            if (temp != NULL) {
                temp = temp->next;
            }
        }

        if (temp == NULL) {
            printf("Position out of range\n");
            return;
        }

        new_node->next = temp->next;
        temp->next = new_node;
    }

    printf("Node inserted\n");
}

void deleteFromBeginning(struct Node** start_ref) {
    struct Node* temp = *start_ref;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    if (*start_ref == (*start_ref)->next) {
        *start_ref = NULL;
    } else {
        *start_ref = temp->next;
        temp->next = NULL;
    }

    free(temp);

    printf("Node deleted\n");
}

void deleteFromLast(struct Node** start_ref) {
    struct Node* temp = *start_ref;
    struct Node* prev;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    if (*start_ref == (*start_ref)->next) {
        *start_ref = NULL;
        free(temp);
    } else {
        while (temp->next != *start_ref) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        temp->next = NULL;
        free(temp);
    }

    printf("Node deleted\n");
}

void deleteFromPosition(struct Node** start_ref, int position) {
    struct Node* temp = *start_ref;
    struct Node* prev;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 1) {
        if (*start_ref == (*start_ref)->next) {
            *start_ref = NULL;
            free(temp);
        } else {
            *start_ref = temp->next;
            temp->next = NULL;
            free(temp);
        }
    } else {
        for (int i = 0; i < position - 2; i++) {
            if (temp != NULL) {
                temp = temp->next;
            }
        }

        if (temp == NULL) {
            printf("Position out of range\n");
            return;
        }

        prev = temp->next;
        temp->next = prev->next;
        prev->next = NULL;
        free(prev);
    }

    printf("Node deleted\n");
}

void printList(struct Node* node) {
    struct Node* temp = node;

    if (node == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Nodes of the Circular Linked List are: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != node);

    printf("\n");
}

int main() {
    struct Node* start = NULL;
    int choice, data, position;

    while (1) {
        printf("1. Insert in beginning\t");
        printf("2. Insert at last\t");
        printf("3. Insert at any position\t");
        printf("\n4. Delete from Beginning\t");
        printf("5. Delete from last\t");
        printf("6. Delete from any position\t");
        printf("\n7. Print Linked List\n");
        printf("8. Exit\n");
        printf("Enter your choice ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the node data? ");
                scanf("%d", &data);
                insertAtBeginning(&start, data);
                break;
            case 2:
                printf("Enter Data? ");
                scanf("%d", &data);
                insertAtLast(&start, data);
                break;
            case 3:
                printf("Enter Data? ");
                scanf("%d", &data);
                printf("Enter position? ");
                scanf("%d", &position);
                insertAtPosition(&start, data, position);
                break;
            case 4:
                deleteFromBeginning(&start);
                break;
            case 5:
                deleteFromLast(&start);
                break;
            case 6:
                printf("Enter position? ");
                scanf("%d", &position);
                deleteFromPosition(&start, position);
                break;
            case 7:
                printList(start);
                break;
            case 8:
            printList(start);
            printf("ExitSuccessFully");
                exit(0);
            default:
                printf("Please enter valid choice\n");
        }
    }

    return 0;
}