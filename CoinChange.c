#include <stdio.h>

#define SIZE 4

int print_ways(int *D, int coin_to_eval, int N)
{   
    if (N == 0)
    {
        return 1;
    }
    else
    {
        int num_ways = 0;
        
        // Include the coin
        if (D[coin_to_eval] <= N)
        {
            num_ways += print_ways(D, coin_to_eval, N-D[coin_to_eval]);
        }
        
        // Exclude the coin and move on to next
        if (coin_to_eval--)
        {
            num_ways += print_ways(D, coin_to_eval, N);
        }
        
        return num_ways;
    }
}

int main()
{
	int N = 8;
    int D[SIZE] = {1,3,5,7};
	printf("Number of ways = %u\n",print_ways(D, SIZE-1, N));

	return 0;
}