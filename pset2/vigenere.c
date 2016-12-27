#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int key_trans(int input);

int main(int argc, string argv[])
{
    // If no argument or more than one command-line argument yell and return 1 
    if (argc != 2)
    {
        printf("Enter one word!\n");
        return 1;
    }
    
    // if alphabetical character in argument yell and return 1 
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        string j = argv[1]; 
        if (isdigit(j[i]))
        {
            printf("Enter one non-negative integer as cmd argument!\n");
            return 1;
        }
    
    }
    
    if (argc != 2)
    {
        return 1;
    }
    else
    {
    
        // define cmd argument as key 
        string key = argv[1];

        // Prompt user for a string of plaintext
        string text = GetString();
        
        // Encipher and output a text with characters rotated by position of a key
        for (int i = 0, k = 0, n = strlen(text); i < n; i++, k++)
        {
            // When all characters of a key are used, start over
            if (k == strlen(key))
            {
                k = 0;
            }
            
            // calculate which character from a key to use
            int j = strlen(key);
            int key_sort = k % j;
            
            // Encipher uppercase characters
            if (isupper(text[i]))   
            {   
                text[i] = (((text[i] - 65) + (key_trans(key[key_sort]))) % 26) + 65;
                printf("%c", text[i]);
            } 
             
            // Encipher lowercase characters
            else if (islower(text[i]))   
            {   
                text[i] = (((text[i] - 97) + (key_trans(key[key_sort]))) % 26) + 97;
                printf("%c", text[i]);
            } 
            
            // Don't encipher non-alphabetical characters 
            else  
            {   
                printf("%c", text[i]);
                k = k - 1;              
            }   
        }
        
        printf("\n");  
        return 0;
    }
}

// treat key character 0 + position in alphabet
int key_trans(int input)
{   
    int output;
    if (input <= 90 && input >= 65)
    {   
        output = input - 65;
    }
    else if (input <= 123 && input >= 97)
    {   
        output = input - 97;
    }
    else
    {
        output = input;
    }
    return output;   
}

