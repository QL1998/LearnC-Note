#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
main()
{
    int len;               /* current line length */
    int max;               /* maximum length seen so far */
    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    
    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) { /* there was a line */
        printf("%d  %s\n", max, longest);
    }
}

/* getLine: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;
    
    i = 0;
    
    while ((c=getchar())!=EOF && c!='\n') {
        if (i < lim - 1) {
            s[i] = c;
            ++i;
        } else {
            ++i;
        }
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
