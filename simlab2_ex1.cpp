#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
#define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    static char ok_chars[] = "abcdefghijklmnopqrstuvwxyz"
                             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                             "1234567890_-.@";
    char *user_data = argv[1];
    char *cp = user_data; /* Cursor into string */
    for (char *cp = user_data; *cp != '\0'; cp++) {
        if (strchr(ok_chars, *cp) == NULL) {
            fprintf(stderr, "Please provide the address of a file as an input.\n");
            return -1;
        }
    }
 
    char cmd[BUFSIZE] = "wc -c < ";
    strcat(cmd, argv[1]);
    system(cmd);
}
