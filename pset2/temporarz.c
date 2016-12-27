 // Prompt user for a string of plaintext
        string text = GetString();
        
        // Encipher and output a text with characters rotated by position of key
        for (int i = 0, n = strlen(text); i < n; i++)
        {
            // Encipher uppercase characters
            if (isupper(text[i]))   
            {   
                text[i] = ((text[i] - 65 + key[(i / strlen(key))]) % 26) + 65;
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
        
        
            // Convert lowercase characters to key
                else if (islower(argv[1][i]))   
                {   
                    key = argv[1][i];
                    key = key - 97;
                    key_done[i] = key;
                    
                    
                 
                } 
                
                /Convert uppercase characters to key
                if (isupper(argv[1][i]))   
                {   
                    argv[1][i] = argv[1][i] - 65;
                    printf("%s", argv[1]);
                   
                } 
                
                
                
                    // if non-alphabetical
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        string key = argv[1];
        if (isdigit(key[i]))
        {
            printf ("Enter one word!\n");
            return 1;
        }
    
    }
