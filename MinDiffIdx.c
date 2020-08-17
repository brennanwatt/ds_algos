#include <stdio.h>

int main()
{
    int a[] = { 1, 3, 5, 4, 8, 2, 4, 3, 6, 5 };
    int x = 2, y = 3;
    int n = sizeof(a) / sizeof(int);
    
    int minDiffIdx = n;
    int curX;
    int haveX = 0;
    int curY;
    int haveY = 0;
    int diff;
    
    for (int i =0; i < n; i++)
    {
        if (a[i] == x)
        {
            if (haveY)
            {
                diff = i - curY;
                if (diff < minDiffIdx)
                {
                    minDiffIdx = diff;
                }
            }
            
            if (!haveX)
            {
                haveX = 1;
            }
            
            curX = i;
        }
        else if (a[i] == y)
        {
            if (haveX)
            {
                diff = i - curX;
                if (diff < minDiffIdx)
                {
                    minDiffIdx = diff;
                }
            }
            
            if (!haveY)
            {
                haveY = 1;
            }
            
            curY = i;
        }
    }
    
    if (minDiffIdx == n)
    {
        printf("Pair not found!\n");
    }
    else
    {
        printf("Min Diff in Idx is %d\n",minDiffIdx);
    }
    
    return 0;
}