
#include <stdio.h>
#include <stdlib.h>
int binarySearch(int *a, int target, int left, int right)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] == target)
        {
            return 1;
        }
        if (a[mid] < target)
        {
    
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return 0;
}

int main()
{
    struct Node *head = NULL;
    int array[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(array) / sizeof(array[0]);
    printf("Given Array [");
    for (int i = 0; i < n; i++)
    {
      printf("%d ",array[i]);
    }
    printf("]\n");
    int target;
    printf("Enter the target value: ");
    scanf("%d", &target);
    if (binarySearch(array, target, 0, n - 1))
    {
        printf("Element %d is present in the list.\n", target);
    }
    else
    {
        printf("Element %d is not present in the list.\n", target);
    }
    return 0;
}