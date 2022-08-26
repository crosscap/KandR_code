#define IN 1
#define OUT 0

int any(char s1[], char s2[])
{
    int i, j;
    int flag;

    for (i = 0; s1[i] != '\0'; i++)
        for (j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])
                return i;

    return -1;
}