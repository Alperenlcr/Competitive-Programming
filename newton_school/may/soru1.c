#include <stdio.h>
int main()
{
    int number;
    scanf("%d", &number);
    if (--number % 3 == 0)
        printf("Dead");
    else
        printf("Alive");
    return 0;
}