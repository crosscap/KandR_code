#include <stdio.h>
#define IN 1
#define OUT 0

int main()
{
    int i, j, c, sum, num, word_length, state;
    int word_lengths[30];
    float percent;

    state = OUT;
    word_length = 0;
    for (i = 0; i < 30; ++i)
    {
        word_lengths[i] = 0;;
    }

    while ( (c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if(state = IN)
            {
                ++word_lengths[word_length];
                word_length = 0;
            }
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++word_length;
        }
        else
        {
            ++word_length;
        }
    }

    for (i = 0; i < 30; ++i)
    {
        sum = sum + word_lengths[i];
    }
    for (i = 0; i < 30; ++i)
    {
        printf("%dword length: \n", i);
        percent = (word_lengths[i] * 1.0) / (sum * 1.0);
        num = percent * 10;
        for (j = 0; j < num; ++num)
            putchar('#');
        putchar('\n');
    }
}