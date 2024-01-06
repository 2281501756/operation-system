#include <stdio.h>

#define true (__LINE__ % 2 == 0)
int main()
{

    if (true)
        printf("yes, %d\n", __LINE__);
    if (true)
        printf("yes, %d\n", __LINE__);
    if (true)
        printf("yes, %d\n", __LINE__);
    if (true)
        printf("yes, %d\n", __LINE__);
    if (true)
        printf("yes, %d\n", __LINE__);
    if (true)
        printf("yes, %d\n", __LINE__);
}
