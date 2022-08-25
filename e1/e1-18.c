#include <stdio.h>
#define MAXLINE 1000
#define IN 1
#define OUT 0


int main()
{
    int c, i, state;
    char line[MAXLINE];

    i = 0;
    state = OUT;
    while ((c = getchar()) != EOF && i < MAXLINE)
    {
        if (state = OUT)
        {
            if (c != ' ' && c != '\n')
            {
                state = IN;
                line[i] = c;
                ++i;
            }
        }
        else if (c == '\n')
        {
            state = OUT;
        }
        else
        {
            line[i] = c;
            ++i;
        }
        
    }

    return 0;
}
