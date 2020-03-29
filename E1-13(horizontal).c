#include <stdio.h>

#define MAX_NUM 100
#define IN 1   /* inside a word */
#define OUT 0  /* outside a word */

/* count lengths of words and draw a histogram */
main()
{
    int c, i, nword, state, temp;
    int lword[MAX_NUM];
    
    nword = 0;
    temp = 0;
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
        temp = lword[i];
        while (lword[i] != 0) {
            printf("-");
            --lword[i];
        }
        lword[i] = temp;
        printf("\n");
        while (lword[i] != 0) {
            printf(" ");
            --lword[i];
        }
        printf("|");
        lword[i] = temp;
        printf("\n");
        while (lword[i] != 0) {
            printf("-");
            --lword[i];
        }
        printf("\n");
    }
    printf("Number of words = %d\n", nword);
}
