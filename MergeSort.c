#include <stdio.h>
void merge(int array[], int start, int mid, int end)
{
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = array[start + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];
    i = 0;
    j = 0;
    k = start;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int array[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);

        merge(array, start, mid, end);
    }
}
int main()
{
    int array[50], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    mergeSort(array, 0, n - 1);
    printf("\nSorted array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    return 0;
}