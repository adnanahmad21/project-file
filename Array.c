#include <stdio.h>

#define MAX_SIZE 100

void insertAtBeginning(int arr[], int *size, int value) {
    if (*size < MAX_SIZE) {
        for (int i = *size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        (*size)++;
    } else {
        printf("Array is full. Cannot insert at beginning.\n");
    }
}

void insertAtLast(int arr[], int *size, int value) {
    if (*size < MAX_SIZE) {
        arr[*size] = value;
        (*size)++;
    } else {
        printf("Array is full. Cannot insert at last.\n");
    }
}

void insertAtPosition(int arr[], int *size, int value, int position) {
    if (*size < MAX_SIZE && position >= 0 && position <= *size) {
        for (int i = *size; i > position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position] = value;
        (*size)++;
    } else {
        printf("Invalid position or array is full. Cannot insert at position %d.\n", position);
    }
}

void deleteFromBeginning(int arr[], int *size) {
    if (*size > 0) {
        for (int i = 0; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
    } else {
        printf("Array is empty. Cannot delete from beginning.\n");
    }
}

void deleteFromLast(int arr[], int *size) {
    if (*size > 0) {
        (*size)--;
    } else {
        printf("Array is empty. Cannot delete from last.\n");
    }
}

void deleteFromPosition(int arr[], int *size, int position) {
    if (*size > 0 && position >= 0 && position < *size) {
        for (int i = position; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
    } else {
        printf("Invalid position or array is empty. Cannot delete from position %d.\n", position);
    }
}

void printArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
    } else {
        printf("Array elements: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, value, position;

    do {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at last\n");
        printf("3. Insert at any position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from last\n");
        printf("6. Delete from any position\n");
        printf("7. Print array\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(arr, &size, value);
                break;
            case 2:
                printf("Enter the value to insert at last: ");
                scanf("%d", &value);
                insertAtLast(arr, &size, value);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(arr, &size, value, position);
                break;
            case 4:
                deleteFromBeginning(arr, &size);
                break;
            case 5:
                deleteFromLast(arr, &size);
                break;
            case 6:
                printf("Enter the position to delete from: ");
                scanf("%d", &position);
                deleteFromPosition(arr, &size, position);
                break;
            case 7:
                printArray(arr, size);
                break;
            case 8:
            printf("Exit Successfully\n  ");
            printArray(arr,size);
             printf("Exit Successfully\n  ");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 8);

    return 0;
}