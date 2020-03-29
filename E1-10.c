#include <stdio.h>

/* count lines in input */
main()
{
    int c, isBlank;
    
    isBlank = 0;
    while ((c = getchar()) != EOF){
        if (c == '\t') {
            printf("\\t");
        } else if (c == ' ') {
            printf("\\b");
        } else if (c == '\\') {
            printf("\\");
        } else {
            putchar(c);
        }
    }
    
}
