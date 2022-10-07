#include "../p5/head.h"
#define MAXLEN 1000
#define MAXSIZE 10000

int getline(char *, int);
char alloc(int);

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines, snum;
    char line[MAXLEN], s[MAXSIZE];

    nlines = 0;
    snum = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (snum+len) > MAXSIZE)
            return -1;
        else
        {
            line[len-1] = '\0';
            strcpy(s+snum, line);
            lineptr[nlines++] = s+snum;
            snum += len;
        }

    return nlines;
}