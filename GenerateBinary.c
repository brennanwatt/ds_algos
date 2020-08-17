#include <stdio.h>

void printBinary(int n)
{
    for (int i = 31; i >=0; i--)
    {
        printf("%d",((n >> i) & 1));
    }
    
    printf("\n");
}

void generate(int n)
{
    if (n < 1)
    {
        return;
    }
    
    generate(n-1);
    
    printBinary(n);
}

// Generate binary numbers between 1 to N
int main()
{
	int n = 16;
	generate(n);

	return 0;
}