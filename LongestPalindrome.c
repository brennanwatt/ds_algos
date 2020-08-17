// complexity O(2^(len(x)+len(y)))
// could memoized (cache sub-problem answers)


#include <stdio.h>
#include <string.h>

#define MAX(a,b)    a > b ? a : b

int LongestPalindrome(char *x, int len_x)
{   
    if (len_x == 0)
    {
        // Empty string
        return 0;
    }
    else if (len_x == 1)
    {
        return 1;
    }
    else if (x[0] == x[len_x-1])
    {
        // Beginning and ending letters match.
        printf("Found match! x=%s, len=%u\n", x, len_x);
        return 2 + LongestPalindrome(&x[1], len_x-2);
    }
    else
    {
        return MAX(LongestPalindrome(&x[1], len_x-1), LongestPalindrome(&x[0], len_x-1));
    }
}

int main()
{
	char* x = "ABBDCACB";
    int len_x = strlen(x);
    
    printf("Longest = %u\n",LongestPalindrome(x, len_x));

	return 0;
}