// complexity O(n^n)
// could be memoized (bottom up approach)


#include <stdio.h>
#include <string.h>

#define MAX(a,b)    a > b ? a : b
#define ELEMENTS    (8)

int MaxProfit(int *len, int *price, int n, int rod_length)
{   
    if (rod_length == 0)
    {
        // Empty string
        return 0;
    }
    else
    {
        int max_profit = 0;
        for (int i=0; i<n; i++)
        {
            if (rod_length >= len[i])
            {
                int profit = price[i] + MaxProfit(len, price, n, rod_length-len[i]);
                if (profit > max_profit)
                {
                    max_profit = profit;
                }
            }
        }
        
        return max_profit;
    }
}

int main()
{
	int len[ELEMENTS] = {1,2,3,4,5,6,7,8};
    int price[ELEMENTS] = {1,5,8,9,10,17,17,20};
    int rod_length = 4;
    
    printf("Max Profit = %u\n",MaxProfit(len, price, ELEMENTS, rod_length));

	return 0;
}

// Bottoms up reference
int rodCut(int price[], int n)
{
	// T[i] stores maximum profit achieved from rod of length i
	int T[n + 1];

	// initialize maximum profit to 0
	for (int i = 0; i <= n; i++)
		T[i] = 0;

	// consider rod of length i
	for (int i = 1; i <= n; i++)
	{
		// divide the rod of length i into two rods of length j
		// and i-j each and take maximum
		for (int j = 1; j <= i; j++)
			T[i] = max(T[i], price[j - 1] + T[i - j]);
	}

	// T[n] stores maximum profit achieved from rod of length n
	return T[n];
}