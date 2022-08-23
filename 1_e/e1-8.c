#include <stdio.h>

int main()
{
    int c, nw;

    nw = 0;
    while ( (c = getchar()) != EOF)
        if (c == ' ')
            ++nw;
        if (c == '\t')
            ++nw;
        if (c == '\n')
            ++nw;
    printf("%d\n", nw);
}