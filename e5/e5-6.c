#include <stdio.h>
#include <ctype.h>

int getline(char *s, int lim)
{
    int c;
    char *bs = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        *s++ = c;
    }
    if (c == '\n')
    {
        *s++ = c;
    }
    *s = '\0';

    return s - bs;
}

int atoi(char *s)
{
    int n, sign;

    while (isspace(*s++))
        ;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    n = 0;
    while (isspace(*s))
    {
        n = 10 * n + (*s - '0');
        s++;
    }

    return sign * n;
}

#include <string.h>

void reverse(char *s)
{
    int c;
    char *t = s;

    while (*t++)
        ;

    while (s < --t)
    {
        c = *s;
        *s = *t;
        *t = c;
        s++;
    }
}
