#include<stdio.h>
#include<limits.h>
 
// Declare heap globally so we don't have to pass it.
int heap[1000000], heapSize;
void Init()
{
    heapSize = 0;
    heap[0] = -INT_MAX;
}

void Insert(int element)
{
    int now = ++heapSize;
    while (heap[now / 2] > element)
    {
        heap[now] = heap[now / 2];
        now /= 2;
    }
    
    heap[now] = element;
}
 
int DeleteMin()
{
    int minElement, lastElement, child, now;
    minElement = heap[1];
    lastElement = heap[heapSize--];
    
    for (now = 1; now * 2 <= heapSize; now = child)
    {
        // Start with left child.
        child = now * 2;

        if (child != heapSize && heap[child + 1] < heap[child])
        {
            child++;
        }
        
        if (lastElement > heap[child])
        {
            heap[now] = heap[child];
        }
        else
        {
            break;
        }
    }
    
    heap[now] = lastElement;
    return minElement;
}
 
int main()
{
    Init();
    
    // Let user populate the heap elements.
    int number_of_elements;
    printf("Program to demonstrate Heap:\nEnter the number of elements: ");
    scanf("%d", &number_of_elements);
    int iter, element;
    printf("Enter the elements: ");
    for (iter = 0; iter < number_of_elements; iter++)
    {
        scanf("%d", &element);
        Insert(element);
    }
    
    // Remove and print minimum elements until heap is empty.
    for (iter = 0; iter < number_of_elements; iter++)
    {
        printf("%d ", DeleteMin());
    }
    printf("\n");
    return 0;
}