#include <ctype.h>

double atof(char s[])
{
    double val, power;
    int i, sign, esign, chenge;

    for (i = 0; isspace(s[i]); ++i)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E')
        i++;

    esign = (s[i] == '-') ? 0 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    while (isdigit(s[i]))
    {
        chenge = chenge * 10 + (s[i] - '0');
        i++;
    }
    if (esign)
        while (chenge)
        {
            power *= 10.0;
            chenge--;
        }
        
    else
        while (chenge)
        {
            power /= 10.0;
            chenge--;
        }
    return sign * val / power;
}