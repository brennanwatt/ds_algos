// complexity O(2^(len(x)+len(y)))
// could memoize (cache sub-problem answers)

#include <stdio.h>
#include <string.h>

#define MAX(a,b)    a > b ? a : b

int LCSLength(char *x, char *y)
{   
    int len_x = strlen(x);
    int len_y = strlen(y);
    
    if (len_x == 0 || len_y == 0)
    {
        return 0;
    }
    else if (x[0] == y[0])
    {
        return 1 + LCSLength(&x[1], &y[1]);
    }
    else
    {
        return MAX(LCSLength(&x[1], &y[0]),LCSLength(&x[0], &y[1]));
    }
    
    return 0;
}

int main()
{
	char* x = "ABCBDAB";
    char* y = "BDCABA";
    
    printf("LCS Length = %u\n",LCSLength(x, y));

	return 0;
}