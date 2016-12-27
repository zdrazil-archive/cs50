#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // ask user for a height of the pyramide
    // validate user prompt
    int blocks;
    do
    {
        printf("How tall should the pyramide be? (max. 23, min. 1 char.)\n");
        blocks = GetInt();
    }
    while (blocks > 23 || blocks < 0);
    
    // build pyramid
    for (int i = 1; i <= (blocks); i++)
    {
        // print spaces
        for (int j = 1; j <= (blocks - i); j++)
        {
            printf(" ");
        }
        
        // print hashes
        for (int k = 1; k <= i + 1; k++)
        {
            printf("#");
        }
        
        // print new line
        printf("\n");
    }  
}
