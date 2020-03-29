#include <stdio.h>

#define MAXLEN 1000

int getLine(char line[], int limitation);
void copy(char from[], char to[]);

/* E1-18: remove trailing blanks and tabs */
main()
{
    int len, i, j;
    char line[MAXLEN];
    char lines[MAXLEN][MAXLEN];
    
    i = 0;
    while ((len = getLine(line, MAXLEN)) > 0) {
        while (line[len] == '\n' || line[len] == '\t' || line[len] == ' ' || line[len] == '\0') {
            --len;
        }
        line[len+1] = '\0';
        copy(line, lines[i++]);
    }
    for (j = 0; j < i; ++j) {
        printf("%s\n", lines[j]);
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

/* copy: copy from 'from' to 'to'; assume to is big enough */
void copy (char from[], char to[])
{
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
