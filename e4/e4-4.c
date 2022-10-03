#define MAXVAL 100      // 栈val的最大深度

int sp = 0;             // 栈顶指针
double val[MAXVAL];     // 值栈

/* 把f压入值栈中 */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* 弹出并返回栈顶的值 */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* 打印栈顶元素 */
void print_stack_top(void)
{
    if (sp)
        printf("error: stack empty\n");
    else
        printf("%f", val[sp]);
}

/* 复制栈顶元素 */
double copy_stack_top(void)
{
    if (sp)
    {
        printf("error: stack empty\n");
        return 0.0;
    }
    else
        return val[sp];
}

/* 交换栈顶元素 */
void copy_stack_top(void)
{
    double temp;

    if (sp)
        printf("error: stack empty\n");
    else if(sp == 1)
        printf("error: stack don't have enough character\n");
    else
    {
        temp = val[sp];
        val[sp] = val[sp+1];
        val[sp+1] = temp;
    }
}

/* 清空栈 */
void clean_stack(void)
{
    sp = 0;
}