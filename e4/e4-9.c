#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE];      // 用于ungetch函数的缓冲区
int bufp = 0;           // buf中下一个空闲位置
int EOF_flag = 0;

int getch(void)         // 取一个字符（可能是压回的字符）
{
    if (!EOF_flag)
    {
        EOF_flag = 0;
        return EOF;
    }
    else
        return (bufp) > 0 ? buf[--bufp] : getchar();
}

int ungetch(int c)      // 把字符压回到输入中
{
    if (bufp > BUFSIZE)
        printf("ungetch: too many characters\n");
    else if (c == EOF)
        EOF_flag = 1;
    else
        buf[bufp++] = c;
}

// 答案解法

#define BUFSIZE 100

int buf[BUFSIZE];      // 用于ungetch函数的缓冲区
int bufp = 0;           // buf中下一个空闲位置

int getch(void)         // 取一个字符（可能是压回的字符）
{
    return (bufp) > 0 ? buf[--bufp] : getchar();
}

int ungetch(int c)      // 把字符压回到输入中
{
    if (bufp > BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}