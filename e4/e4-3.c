#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pull(void);
int getch(void);
void ungetch(int);

int main()
{
    int type;
    double op2;
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
            case '%':
                op2 = pop();
                if (op2 = 0.0)
                    printf("error: zero devisor\n");
                else
                    push(pop() % (int) op2);
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

int getop(char s[])
{
    int i, c;

    while ((s[0] = c =getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    i = 0;
    if (c == '-')
    {
        if (isdigit(c = getch()) || c == '.')
            s[++i] = c;
        else
        {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    }
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    
    return NUMBER;
}