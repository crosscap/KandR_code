#define IN 1
#define OUT 0
void squeeze(char s1[], char s2[])
{
    int i, j, k;
    int flag;

    for (i = k = 0; s1[i] != '\0'; i++)
    {
        flag = OUT;
        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
            {
                flag = IN;
                break;
            }
        }
        if (flag = IN)
            s1[k++] = s1[i];
    }
    s1[k] = '\0';
}