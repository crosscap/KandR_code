//undone

#include <stdio.h>

/* tail function */
int main(int argc, char *argv[])
{
    int i, printno = 10;

    if (argc = 1)
    {
        if ((*++argv)[0] == '-')
        {
            for (i = 1, printno = 0; *argv[i] != '\0'; i++)
            {
                printno *= 10;
                printno += (*argv[i] - '0');
            }
        }
        else
        {
            printf("error: input wrong\n");
            return 1;
        }
    }


    return 0;
}
