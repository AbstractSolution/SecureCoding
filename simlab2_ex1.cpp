#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
#define BUFSIZE 256


int sanitizeWhitelist(char *user_data, char *ok_chars)
{
    for (char *cp = user_data; *cp != '\0'; cp++)
    {
        if (strchr(ok_chars, *cp) == NULL)
        {
            fprintf(stderr, "Please provide the address of a file as an input.\n");
            return -1;
        }
    }
    return 0;
}
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    static char ok_chars[] = "abcdefghijklmnopqrstuvwxyz"
                             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                             "1234567890_-.@"; // Whitelist characters to sanitize the input.
    char *user_data = argv[1];
    char *cp = user_data; /* Cursor into string */
    for (char *cp = user_data; *cp != '\0'; cp++) {
        if (strchr(ok_chars, *cp) == NULL) {
            fprintf(stderr, "Please provide the address of a file as an input.\n");
            return -1;
        }
    }
 
    if (strlen(argv[1]) > 247 || strlen(argv[1]) == 0) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    else
    {
        if (sanitizeWhitelist(argv[1], ok_chars) != 0)
        {
           return -1;
        }
        else
        {
           FILE *file = fopen(argv[1], "rb");
           if (file == NULL)
           {
               fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
               return -1;
           }

           // Get file size
           fseek(file, 0, SEEK_END);
           long size = ftell(file);
           fclose(file);

           // Print the size
           printf("%ld\n", size);
        }
    }
 
    
}
