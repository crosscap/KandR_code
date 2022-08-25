void reverse(char s[])
{
    int front, rear;
    char temp;

    front = rear = 0;
    while (s[rear+1] != '\0')
    {
        ++rear;
    }
    if (s[rear] == '\n')
    {
        --rear;
    }
    while (front < rear)
    {
        temp = s[front];
        s[front] = s[rear];
        s[rear] = temp;
        front++;
        rear--;
    }

    return;
}