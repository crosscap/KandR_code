void strncpy(char *s, char *t, int n)
{
    while (*s++ = *t++ && --n > 0)
        continue;
    while(n-- > 0)
        *s++ = '\0';
}

void strncat(char *s, char *t, int n)
{
    while (*s++)
        ;
    while (*s++ = *t++ && --n)
        ;
}

int strncmp(char *s, char *t, int n)
{
    for (; *s == *t; s++, t++)
        if (*s == '\0' && --n <= 0)
            return 0;
    return *s - *t;
}
