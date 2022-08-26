#include <stdio.h>
unsigned rightrot(unsigned x, int n)
{
    int i;
    unsigned lowest;
    for (i = 0; i < n; ++i)
    {
        lowest = x & ~((~0) << 1);
        if (lowest == 0)
            x = (x >> 1);
        else
            x = (x >> 1 | ~((~0) >> 1));
    }

    return x;
}

int main(void)
{
    printf("%x", rightrot(0x7ff, 2));
}