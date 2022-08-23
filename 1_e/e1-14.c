#include <stdio.h>

int main()
{
    int c, i, j, sum, num, cs_num; // cs_num: the char can be seen
    int ascii[128];
    float percent;

    for (i = 0; i < 128; ++i)
    {
        ascii[i] = 0;
    }
    while ((c = getchar()) != EOF)
    {
        ++ascii[c];
    }

    for (i = 0; i < 128; ++i)
    {
        sum = sum + ascii[i];
    }
    for (i = 0; i < 128; ++i)
    {
        printf("ASCII number: %d\n", i);
        percent = (ascii[i] * 1.0) / (sum * 1.0);
        num = percent * 10;
        for (j = 0; j < num; ++num)
            putchar('#');
        putchar('\n');
    }
}