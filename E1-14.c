#include <stdio.h>

#define CHAR_NUM 26*2

/* count frequencies of characters and draw a histogram */
main()
{
    int c, i, j, max;
    int fchar[CHAR_NUM]; /* store the frequencies of lowercase and uppercase characters */
    
    max = 0;
    for (i = 0; i < CHAR_NUM; ++i) {
        fchar[i] = 0;
    }
    
    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') {
            ++fchar[c-'a'];
        } else if (c >= 'A' && c <= 'Z') {
            ++fchar[c-'A'+26];
        }
    }
    
    printf("-----Lengths of words-----\n");
    for (i = 0; i < CHAR_NUM; ++i) {
        if (fchar[i] > max) {
            max = fchar[i];  /* the max height of histogram */
        }
    }
    for (j = 0; j < max; ++j) {
        for (i = 0; i < CHAR_NUM; ++i) {
            if (max - j - 1 < fchar[i]) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    for (i = 0; i < CHAR_NUM; ++i) {
        if (i < 26) {
            printf("%c ", i + 'a');
        } else if (i < CHAR_NUM-1){
            printf("%c ", i - 26  + 'A');
        } else {
            printf("%c", i - 26 + 'A');
        }
    }
    printf("\n");
}
