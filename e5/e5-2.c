#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

// 将输入中的下一个整型数返回给*pn
int ghetfloat(float *pn)
{
    int c, sign;
    float power;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' | c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');
    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch())
    {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;
    }
    *pn /= power;
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
