// ret
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100       // 操作符或运算符的最大长度
#define NUMBER '0'      // 标识找到一个数

int getop(char []);
void push(double);
double pull(void);

int varialbe[26];

int main()
{
    int type;
    int var = 0;
    double op2, v;
    char s[MAXOP];

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
            case '=':
                pop();
                if (isupper(var))
                    varialbe[type - 'A'] = pop();
                else
                    printf("error: no variable name\n");
            case '\n':
                v = pop();
                printf("\t.8g\n", v);
                break;
            default:
                if (isupper(type))
                    push(varialbe[type - 'A']);
                else if (type == 'v')
                    push(v);
                else
                    printf("unknown cammand %s\n", s);
                break;
        }

        var = type;
    }

    return 0;
}