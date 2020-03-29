#include <stdio.h>

#define MAXLEN 1000

int getLine(char line[], int limitation);
void reverse(char from[], char to[]);

/* E1-19: reverse an input line at a time */
main()
{
    int len, i, j;
    char line[MAXLEN];
    char newline[MAXLEN];
    
    i = 0;
    while ((len = getLine(line, MAXLEN)) > 0) {
        if (line[len-1] == '\n') {   /* line[len] would be '\0' */
            line[len-1] = '\0';      /* remove the ending '\n' before '\0' */
        }
        reverse(line, newline);
        printf("%s\n", newline);
        
    }
    return 0;
}

/* getLine: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;
    
    for (i = 0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* reverse: reverse 'from' to 'to'; assume to is big enough */
void reverse(char from[], char to[])
{
    int i, len;
    
    i = len = 0;
    while (from[len] != '\0') {
        ++len;
    }
    
    while (i < len) {
        to[i] = from[len-i-1];
        ++i;
    }
    to[len] = '\0';
}
