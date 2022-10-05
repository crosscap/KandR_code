/* 不能处理s长度小于t的情况
void strend(char *s, char *t)
{
    char *tp = t;

    while (*s++)
        ;
    while (*t++)
        ;
    while (*t-- == *s-- && t > tp)
        ;
    if (t == tp)
        return 1;
    else
        return 0;
}
*/

void strend(char *s, char *t)
{
    char *bs = s;
    char *bt = t;

    while (*s++)
        ;
    while (*t++)
        ;
    while (*t == *s && s > bs && t > bt)
    {
        if (t == bt || s == bs)
            break;
        s--;
        t--;
    }
    if (*s == *t && t == bt && *s != '\0')
        return 1;
    else
        return 0;
}