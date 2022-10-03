#include <stdio.h>
#include <ctype.h>
#include "../p4/calc.h"

static int next = -1;

/* 获取下一个运算符或数值操作数 */
int getop(char s[])
{
    int i, c;

    if (next == -1)
    {
        s[0] = c = next;
        next = -1;
    }
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    
    s[1] = '\0';
    if (!isdigit(c) && c != '.')        // 不是数
        return c;
    i = 0;
    if (isdigit(c))                     // 收集整数部分
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')                       // 收集小数部分
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        next = c;
    
    return NUMBER;
}