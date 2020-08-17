#include <stdio.h>

void swap(int a[], int idxA, int idxB)
{
    int temp = a[idxA];
    a[idxA] = a[idxB];
    a[idxB] = temp;
}

int partitionOnPivot(int a[], int startIdx, int endIdx)
{
    int pivotIdx = startIdx;
    int pivotValue = a[endIdx];
    
    for (int i = startIdx; i < endIdx; i++)
    {
        if (a[i] <= pivotValue)
        {
            swap(a, i, pivotIdx);
            pivotIdx++;
        }
    }
    
    // Move the pivot into proper position.
    swap(a, pivotIdx, endIdx);
    
    return pivotIdx;
}

void quickSort(int a[], int startIdx, int endIdx)
{
    if (startIdx >= endIdx)
    {
        // All done!
        return;
    }
    
    int pivotIdx = partitionOnPivot(a, startIdx, endIdx);
    
    // Sort the values smaller than the pivot.
    quickSort(a, startIdx, pivotIdx - 1);
    
    // Sort the values larger than the pivot.
    quickSort(a, pivotIdx + 1, endIdx);
}

void findPair(int a[], int n, int sum)
{
    int i = 0;
    int j = n-1;
    while (i < j)
    {
        int pairSum = a[i] + a[j];
        if (pairSum == sum)
        {
            // Found it!
            printf("Found pair at idx a[%d]=%d and a[%d]=%d\n",i,a[i],j,a[j]);
            return;
        }
        else if (pairSum > sum)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    
    printf("No pair exists");
}

int main()
{
    int a[] = {8, 7, 2, 5, 3, 1};
    int sum = 10;
    int n = sizeof(a) / sizeof(int);
    
    printf("Starting quick sort on array of size %u\n",n);
    int startIdx = 0;
    int endIdx = n-1;
    quickSort(a, startIdx, endIdx);
    
    printf("Sorted array:\n");
    for(int i=0; i < n; i++)
    {
        printf("%d\n",a[i]);
    }
    
    findPair(a, n, sum);
    
    return 0;
}