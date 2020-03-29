#include <stdio.h>
 
/* count lines in input */
main()
{
    int c, isBlank;
    
    isBlank = 0;
    while ((c = getchar()) != EOF){
        while (c == ' ') {
            isBlank = 1;
            c = getchar();
        }
        if (isBlank == 1) {
            putchar(' ');
        }
        putchar(c);
        isBlank = 0;
    }
    
}
