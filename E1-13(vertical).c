#include <stdio.h>

#define MAX_NUM 100
#define IN 1   /* inside a word */
#define OUT 0  /* outside a word */

/* count lengths of words and draw a histogram */
main()
{
    int c, i, j, nword, state, max;
    int lword[MAX_NUM];
    
    nword = 0;
    max = 0;
    state = OUT;
    for (i = 0; i < MAX_NUM; ++i) {
        lword[i] = 0;
    }
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            lword[nword] = 1;
            ++nword;
        } else if (state == IN) {
            lword[nword-1]++;
        }
    }
    
    printf("-----Lengths of words-----\n");
    for (i = 0; i < nword; ++i) {
        if (lword[i] > max) {
            max = lword[i];  /* the max height of histogram */
        }
    }
    for (j = 0; j < max; ++j) {
        for (i = 0; i < nword; ++i) {
            if (max - j - 1 < lword[i]) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("Number of words = %d\n", nword);
}
