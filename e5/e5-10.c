#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

#define MAXOP 100       // 操作符或运算符的最大长度

int main(int argc, char *argv[])
{
    double op2;
    char s[MAXOP];

    while (--argc > 0)
    {
        strcpy(s, *(argv++));
        switch (getop(s))
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