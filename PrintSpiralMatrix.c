#include <stdio.h>

#define DEBUG 1

#define M 5
#define N 5

int mat[M][N] =
{
    { 1,  2,  3,  4, 5},
    {16, 17, 18, 19, 6},
    {15, 24, 25, 20, 7},
    {14, 23, 22, 21, 8},
    {13, 12, 11, 10, 9}
};

void printElement(int y, int x)
{
#if DEBUG
    printf("Printing location mat[%d][%d]\n", y, x);
#endif
    printf("%d ",mat[y][x]);
#if DEBUG
    printf("\n");
#endif
}

void printSpiralOrder()
{
    int top = 0, bottom = M - 1;
	int left = 0, right = N - 1;

	while (1)
	{
		if (left > right)
			break;
		// print top row
		for (int i = left; i <= right; i++)
			printf("%d ",mat[top][i]);
		top++;

		if (top > bottom)
			break;
		// print right column
		for (int i = top; i <= bottom; i++)
			printf("%d ",mat[i][right]);
		right--;

		if (left > right)
			break;
		// print bottom row
		for (int i = right; i >= left; i--)
			printf("%d ",mat[bottom][i]);
		bottom--;

		if (top > bottom)
			break;
		// print left column
		for (int i = bottom; i >= top; i--)
			printf("%d ",mat[i][left]);
		left++;
	}
}

int main()
{
	printSpiralOrder();
	return 0;
}