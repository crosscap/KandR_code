static int num = 0;
void itoa(int n, char s[])
{
    if (n < 0)
    {
        s[0] = '-';
        num++;
        n = -n;
    }
    if (n / 10)
        itoa(n / 10, s);
    s[num++] = (n % 10 + '0');
    s[num] = '\0';
}