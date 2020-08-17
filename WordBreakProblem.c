// complexity O(n^2) for evaluating every sub-array approach
// complexity O(n log n) for sorting + binary search approach
// complexity O(n) for hashing approach, with space complexity O(n)


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX(a,b)    a > b ? a : b
#define ELEMENTS    (16)
#define MAX_OUTPUT_SIZE (100)

int num_solutions = 0;

void Wordbreak(char *match, char **A, int dict_size, char *output)
{
    if (strlen(match) == 0)
    {
        strcat(output, "\0");
        printf("Solution = %s\n",output);
        free(output);
        num_solutions++;
        return;
    }
    
    for (int i=0; i<dict_size; i++)
    {
        int len = strlen(A[i]);
        bool full_match = true;
        for (int j=0; j<len; j++)
        {
            if (match[j] != A[i][j])
            {
                full_match = false;
                break;
            }
        }
        
        if (full_match)
        {
            char *output_buffer = (char*)malloc(MAX_OUTPUT_SIZE*sizeof(char));
            strcpy(output_buffer, output);
            strcat(output_buffer, A[i]);
            strcat(output_buffer, " ");
            Wordbreak(&match[len], A, dict_size, output_buffer);
        }
    }
}

char output[MAX_OUTPUT_SIZE];

int main()
{
    char *match = "Wordbreakproblem";
	char *array[ELEMENTS] = { "this", "th", "is", "famous", "Word", "break", "b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };
    
    Wordbreak(match, array, ELEMENTS, &output[0]);
    printf("\nfinished with %u solutions!\n", num_solutions);

	return 0;
}