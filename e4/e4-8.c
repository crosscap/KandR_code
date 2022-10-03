#define BUFSIZE 100

char buf;
int buf_flag = 0;

int getch(void)         // 取一个字符（可能是压回的字符）
{
    if (buf_flag)
        return getchar();
    else
    {
        buf_flag = 0;
        return buf;
    }
}

int ungetch(int c)      // 把字符压回到输入中
{
    if (buf_flag)
        printf("ungetch: too many characters\n");
    else
    {
        buf = c;
        buf_flag = 1;
    }
}