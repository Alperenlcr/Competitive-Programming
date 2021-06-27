#include <stdio.h>

int solution(int* x, int* f)
{
    int y = *f;
    if (y > (int)(*x/2))
        y = (int)(*x/2);
    while (y != 1 && *x%y != 0)
        y -= 1;
    if (y == 1)
        return 1;
    else
        *x += y;
        *f -= y;
        return 0;
}
int main()
{
    int a, b, f;
    scanf("%d, %d", &a, &b);
    if (a>=b-1 && a*2<=b)
        printf("No");
    else
    {
        f = b-a;
        while (f != 0 && !solution(&a, &f));
        if (f == 0)
            printf("Yes");
        else
            printf("No");
    }
}