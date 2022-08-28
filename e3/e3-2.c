void escape(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while (t[i])
    {
        switch (t[i])
        {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            ++i;
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            ++i;
            break;
        case '\b':
            s[j++] = '\\';
            s[j++] = 'b';
            ++i;
            break;
        case '\\':
            s[j++] = '\\';
            s[j++] = '\\';
            ++i;
            break;
        default:
            s[j++] = t[i++];
            break;
        }
    }
    s[j] = '\0';
}

void reescape(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while (t[i])
    {
        switch (t[i])
        {
        case '\\':
            switch (t[i+1])
            {
                case 'n':
                    s[j++] = '\n';
                    i += 2;
                    break;
                case 't':
                    s[j++] = '\t';
                    i += 2;
                    break;
                case 'b':
                    s[j++] = '\b';
                    i += 2;
                    break;
                case '\\':
                    s[j++] = '\\';
                    i += 2;
                    break;
                default:
                    i += 2;
                    break;
            }
            break;
        default:
            s[j++] = t[i++];
            break;
        }
    }
}