#include "thread.c"

void t1()
{
    while (1)
    {
        printf("A");
    }
}
void t2()
{
    while (1)
    {
        printf("B");
    }
}

int main()
{
    create(t1);
    create(t2);
}