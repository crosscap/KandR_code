#include <ctype.h>

void expand(char s1[], char s2[])
{
    int i, j;
    char c;

    for (i = 0, j = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] == '-' && isalnum(s1[i+1]) && s1[i+1] > s1[i-1])
        {
            for (c = s1[i-1] + 1; c <= s1[i+1]; c++)
                s2[j++] = c;
            i++;
        }
        else
            s2[j++] = s1[i];
    }
    s2[j] = '\0';
}