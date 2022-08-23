#include <stdio.h>

int main()
{
    int c, pc, nw;

    pc = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            if (pc != ' ')
            putchar(c);
        if (c != ' ')
            putchar(c);
        pc = c;
    }
}