#include <stdio.h>

#define DP          (1)

#define ITEMS       (6)
#define CAPACITY    (10)

int memoized[ITEMS][CAPACITY+1];

int knapsack(int v[], int w[], int curItem, int weightRemaining)
{
    if (curItem < 0 || weightRemaining == 0)
    {
        return 0;
    }
    
    int value;
#if DP
    printf ("Memoized value for [%d][%d] = %d\n",curItem,weightRemaining,memoized[curItem][weightRemaining]);
    if (memoized[curItem][weightRemaining] == -1)
#endif
    {
        int nextItem = curItem-1;
        if (w[curItem] > weightRemaining)
        {
            value = knapsack(v, w, nextItem, weightRemaining);
        }
        else
        {
            int include = v[curItem] + knapsack(v, w, nextItem, weightRemaining-w[curItem]);
            int exclude = knapsack(v, w, nextItem, weightRemaining);
            
            if (include > exclude)
            {
                value = include;
            }
            else
            {
                value = exclude;
            }
        }
        
        memoized[curItem][weightRemaining] = value;
    }

#if DP
    return memoized[curItem][weightRemaining];
#else
    return value;
#endif
}

int main()
{
    // Input: set of items each with a weight and a value
    int v[] = { 20, 5, 10, 40, 15, 25 };
    int w[] = {  1, 2,  3,  8,  7, 4 };
    
#if DP
    for (int i=0; i < ITEMS; i++)
    {
        for (int j=0; j < CAPACITY+1; j++)
        {
            memoized[i][j] = -1;
        }
    }
#endif
    
    printf("Maximum value = %d\n",knapsack(v, w, ITEMS-1, CAPACITY));
    
    return 0;
}