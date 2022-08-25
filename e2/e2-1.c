#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("char    max: %d, min: %d, unsigend max: %u\n", CHAR_MAX,    CHAR_MIN,   UCHAR_MAX);
    printf("short   max: %d, min: %d, unsigend max: %u\n", SHRT_MAX,    SHRT_MIN,   SHRT_MAX);
    printf("int     max: %d, min: %d, unsigend max: %u\n", INT_MAX,     INT_MIN,    UINT_MAX);
    printf("long    max: %ld, min: %ld, unsigend max: %lu\n", LONG_MAX, LONG_MIN,   ULONG_MAX);

    return 0;
}