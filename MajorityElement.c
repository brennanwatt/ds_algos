// complexity O(n^2) for evaluating every sub-array approach
// complexity O(n log n) for sorting + binary search approach
// complexity O(n) for hashing approach, with space complexity O(n)


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX(a,b)    a > b ? a : b
#define ELEMENTS    (11)

int MajorityElement(int *A, int n)
{   
    for (int i=0; i<n; i++)
    {
        int count=1;
        for (int j=i+1; j<n; j++)
        {
            if (A[i] == A[j])
            {
                count++;
            }
        }
        
        if (count > n/2)
        {
            printf("Majority Element %u found %u times\n",A[i], count);
            return true;
        }
    }
}

int pivot(int *A, int start, int end)
{
    int pivot_idx = start;
    
    for (int i=start+1; i<end; i++)
    {
        if (A[pivot_idx] > A[i])
        {
            int temp = A[pivot_idx];
            A[pivot_idx] = A[i];
            A[i] = A[++pivot_idx];
            A[pivot_idx] = temp;
        }
    }
    
    return pivot_idx;
}

void QuickSort(int *A, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    
    int p = pivot(A, start, end);
    QuickSort(A, start, p);
    QuickSort(A, p+1, end);
}

int MajorityElementSearch(int *A, int n)
{
    int start_idx = 0;
    for (int i=0; i<n; i++)
    {
        if (A[i] != A[start_idx])
        {
            int count = i-start_idx;
            if (count > n/2)
            {
                printf("Majority Element %u found %u times\n",A[start_idx], count);
                return true;
            }
            else
            {
                start_idx = i;
            }
        }
    }
}

int counts[ELEMENTS] = {0};

int MajorityElementHash(int *A, int n)
{
    for (int i=0; i<n; i++)
    {
        if(++counts[A[i]] > n/2)
        {
            printf("Majority Element %u found %u times\n",A[i], counts[A[i]]);
            return true;
        }
    }
}

int main()
{
	int array[ELEMENTS] = { 2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2 };
    
    MajorityElement(array, ELEMENTS);
    
    QuickSort(array, 0, ELEMENTS);
    MajorityElementSearch(array, ELEMENTS);
    
    MajorityElementHash(array, ELEMENTS);

	return 0;
}