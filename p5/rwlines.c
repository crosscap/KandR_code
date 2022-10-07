#include "head.h"
#define MAXLEN 1000

int getline(char *, int);
char alloc(int);

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len) == NULL))
            return -1;
        else
        {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }

    return nlines;
}

/* 数组方式实现
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i < 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}
*/

void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}