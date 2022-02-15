#include <stdio.h>
int main()
{
    unsigned int number1,number2,number3;
    scanf("%d %d %d", &number1, &number2, &number3);
    if ((number1<number2 && number2<number3) || (number3<number2 && number2<number1))
        printf("%d", number2);
    else if ((number3<number1 && number1<number2) || (number2<number1 && number1<number3))
        printf("%d", number1);
    else
        printf("%d", number3);
    return 0;
}