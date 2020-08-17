#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int WaysToDecode(char *message)
{
    if (strlen(message) == 0)
    {
        // We've processed entire message. Successful decode!
        return 1;
    }
    else
    {
        int num_ways = 0;
        for (int i=1; i<=26; i++)
        {
            bool match = true;
            char temp[3];
            sprintf(temp, "%d", i);

            for (int j=0; j<strlen(temp); j++)
            {
                if (temp[j] != message[j])
                {
                    match = false;
                    break;
                }
            }
            
            if (match)
            {
                num_ways +=  WaysToDecode(&message[strlen(temp)]);
            }
        }
        
        return num_ways;
    }
}

int main()
{
    char *message = "123456781223123212";
    
    printf("There are %u ways to decode the message\n",WaysToDecode(message));

	return 0;
}