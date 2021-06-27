#include <stdio.h>
#include <math.h>
#include <time.h>

int solution(long* x, long* f)
{
    long y = *f;
    while (y != 1 && *x%y != 0)
        y --;
    if (y == 1)
        return 1;
    else
        *x += y;
        *f -= y;
        return 0;
}
int main()
{
    int msec = 0, trigger = 10; /* 10ms */
    clock_t before = clock();
    long a, b, f;
    scanf("%ld %ld", &a, &b);
    if (a>=b-1 || a*2<=b)
        printf("No");
    else
    {
        f = b-a;
        while ( msec < trigger && f != 0 && !solution(&a, &f))
        {
            clock_t difference = clock() - before;
            msec = difference * 1000 / CLOCKS_PER_SEC;
        }
        if (f == 0)
            printf("Yes");
        else
            printf("No");
    }
}