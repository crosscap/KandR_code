// ret

void reverse(char s[])
{
    void reverse_b(char s[], int left, int right);

    reverse_b(s, 0, strlen(s));
}
void reverse_b(char s[], int left, int right)
{
    char c;

    if (left < right)
    {
        c = s[left];
        s[left] = s[right];
        s[right] = c;
        reverse_b(s, ++left, --right);
    }
}