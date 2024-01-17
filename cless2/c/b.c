#include "thread.c"
#define N 100000

long sum = 0;

void Tsum()
{
    for (int i = 0; i < N; i++)
    {
        sum++;
    }
}

int main()
{
    create(Tsum);
    create(Tsum);
    join();
    printf("%ld\n", sum);
}