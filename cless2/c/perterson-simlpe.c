#include "thread.c"

#define A 1
#define B 1

atomic_int nested;
atomic_long count;

void critical_section()
{
    atomic_fetch_add(&count, 1);
    assert(atomic_fetch_add(&nested, 1) == 0);
    atomic_fetch_add(&nested, -1);
}

int volatile x = 0, y = 0,  ture = A;


void TA()
{
    while (1)
    {
        x = 1;
        ture = B;
        while (y && ture == B);
        critical_section();
        x = 0;
    }
    
}

void TB()
{
    while (1)
    {
        y = 1;
        ture = A;
        while(x && ture == A);
        critical_section();
        y = 0;
    }
    
}

int main()
{
    create(TA);
    create(TB);
}