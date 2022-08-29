#include <string.h>
void reverse(char s[]);

void itoa(int n, char s[])
{
    int i, sign, flag;

    flag = 1;
    if ((sign = n) < 0)
    {
        if ((n - 1) > 0)
        {
            n += 1;
            flag = 0;
        }
        n = -n;
    }
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while((n /= 10) > 0);
    if (flag)
        s[i] += 1;
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}