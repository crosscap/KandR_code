// ret
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 100         // 操作符或运算符的最大长度
#define NUMBER '0'          // 标识找到一个数

int getop(char []);
void push(double);
double pull(void);
int getch(void);
void ungetch(int);

int lim = 0;
char line[MAXLINE];

int main()
{
    int type;
    double op2;
    char s[MAXLINE];
    
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atofs(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero devisor\n");
                break;
            case '\n':
                printf("\t.8g\n", pop());
                break;
            default:
                printf("unknown cammand %s\n", s);
                break;
        }
    }

    return 0;
}

/* 获取下一个运算符或数值操作数 */
int getop(char s[])
{
    int i, c;

    if (line[lim] == '\0')
        if (getline(line, MAXLINE, '\n') == 0)
            return EOF;
        else
            lim = 0;
    while ((s[0] = c = line[lim++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')        // 不是数
        return c;
    i = 0;
    if (isdigit(c))                     // 收集整数部分
        while (isdigit(s[++i] = c = line[lim++]))
            ;
    if (c == '.')                       // 收集小数部分
        while (isdigit(s[++i] = c = line[lim++]))
            ;
    s[i] = '\0';
    lim--;
    
    return NUMBER;
}