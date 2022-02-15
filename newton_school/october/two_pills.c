#include <stdio.h>
int main()
{
    int M,Y,R, G;
    scanf("%d %d %d %d", &M, &Y, &R, &G);
    if (M<Y*G)
        printf("1");
    else if (M<Y+R)
        printf("1");
    else
        printf("0");
    return 0;
}