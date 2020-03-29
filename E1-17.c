#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
main()
{
    int len;               /* current line length */
    int max;               /* maximum length seen so far */
    int nlongline, i;
    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE][MAXLINE]; /* longest line saved here */
    
    max = 0;
    nlongline = 0;
    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > 80) {
            copy(longest[nlongline++], line);
        }
    }
    printf("%d\n", nlongline);
    for (i = 0; i < nlongline; ++i) {
        printf("%s", longest[i]);
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
