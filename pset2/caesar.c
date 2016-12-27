#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    // if alphabetical
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        string j = argv[1]; 
        if (isalphaj[i]))
        {
            printf ("Enter one non-negative integer as cmd argument!\n");
            return 1;
        }
    
    }

    // If no argument or more than one command-line argument yell and return 1 
    if (argc != 2)
    {
        printf ("Enter one non-negative integer as cmd argument!\n");
        return 1;
    }
     
    else
    {
        // convert single-command to an integer
        int key = atoi(argv[1]);
        // Prompt user for a string of plaintext
        string text = GetString();
        
        // Encipher and output a text with characters rotated by position of key
        for (int i = 0, n = strlen(text); i < n; i++)
        {
            // Encipher uppercase characters
            if (isupper(text[i]))   
            {   
                text[i] = ((text[i] - 65 + key) % 26) + 65;
                printf("%c", text[i]);
            } 
             
            // Encipher lowercase characters
            else if (islower(text[i]))   
            {   
                text[i] = ((text[i] - 97 + key) % 26) + 97;
                printf("%c", text[i]);
            } 
            
            // Don't encipher non-alphabetical characters 
            else  
            {   
                printf("%c", text[i]);
            }   
        }
        printf("\n");  
        return 0;
    }
}
